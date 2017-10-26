#include "simulation.hpp"
#include <cstdlib>
#include <array>
#include <list>

Simulation::Simulation(double timestep)
			:H(timestep),StepTime(0)
			{ 	cout<< "You are intialising a simulation" << endl <<"Please enter settings" <<endl;
				SetSimTime();
				SetCurrent();	
			}

Simulation::~Simulation()
			{
				for(auto& cell: Cells)
				{
					delete cell;
					cell=nullptr;
				}
				
			}
			
void Simulation::SetSimTime()
{

	//check the imput
	do {
		cout << endl << "Set simulation time in ms : ";
		cin>> SimTime;	
	} while(SimTime<0);
	
	/*if (!cin) // same as cin.fail() checking value type
	{
		cin.clear();
		cin.ignore(1000);
		cout << "Invalid value type, please enter value again : " ;
	}*/
}



void Simulation::SetCurrent()
{
	//check the imput
	cout<< "Set value of external current apllied to neuron 1: ";
	cin>>Iext;
	cout << "Set time limits : a=";
	cin>>abound;
	cout << "b=";
	cin>>bbound;
}

void Simulation::NewNeuron(string name)
{
	Neuron* n1 = new Neuron (name);
	/*'doesn't like it, copies are created!! how to avoid it ?'*/
	Cells.push_back(n1); // creating a dynamic neuron avoid copies
	// for now all cells are neigbors
}

void Simulation::Run()
{
	NewNeuron("n1");
	NewNeuron("n2");
	Cells[1]->setMembPot(0);
	Network();
	//opening channel to store membrane potentials
	ofstream history;
	history.open("history.txt");	
	
	//updating cell
	do{
		NeuronsUpdate();
		
		//incremeting simulation Time in steps
		StepTime+=1;
	}
	while(RealTime(StepTime)< SimTime); //checkingif simulation has reached it's end in ms
	
	cout << "Neuron 1 has fired " << Cells[0]->Neuron::getSpikeNumb() << " times" <<endl;
	cout << "Neuron 2 has fired " << Cells[1]->Neuron::getSpikeNumb() << " times" <<endl;
	
}


void Simulation::NeuronsUpdate()
{
	//allows to stimulate only one neuron in network
	if(RealTime(StepTime)>abound and RealTime(StepTime)< bbound) //checking time is in stimulation bounds in ms
	{
		Cells[0]->setStim(1);
	}
	
	//updating all neurons in simulation
	for (auto& cell: Cells)
	{
		cell->Neuron::Update(H, RealTime(StepTime), Iext);  //need to convert to realtime since neuron doesn't know H value
	}
}

void Simulation::Network()
{
	int size = Cells.size()*0.1;
	
	for(auto& cell:Cells)
	{	//create for each neuron an array of neighbors randomly selected from Cells
		Neuron** neighbors=new Neuron*[size]; //creation of array with appropriate size and memory storage
		list<int> possible ;  //list created filled with all possible indexes for neurons in sim
		for (int i (0); i < Cells.size() ; ++i)
		{
			possible.push_back(i);
		}
		
		for (int i (0); i <size ; ++i)
		{
			//a la con copie des indexes et relation avec soi meme
			// solution potentielle:  liste chainée des indexes et virer le sien et virer ceux déja tirés
			
			int index= rand() % Cells.size();
			neighbors[i]=Cells[index];
		}

		cell->AddNeighbors(neighbors, size);
		delete neighbors;
	}
}

double Simulation::RealTime(double time)
{
	return time*H;
}
