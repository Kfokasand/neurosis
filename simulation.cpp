#include "simulation.hpp"


Simulation::Simulation(double timestep, int time)
			:TimeStep(timestep), Time(time)
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
	cout<< "Set value of external current apllied to neuron 1:";
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
		
		//incremeting simulation Time
		Time+=1;
	}
	while(Time*TimeStep< SimTime);

	cout << Time*TimeStep << endl;
	
	cout << "Neuron 1 has fired " << Cells[0]->Neuron::getSpikeNumb() << " times" <<endl;
	cout << "Neuron 2 has fired " << Cells[1]->Neuron::getSpikeNumb() << " times" <<endl;
	
}



bool Simulation::NeuronsUpdate()
{
	if(Time*TimeStep>abound and Time*TimeStep< bbound)
	{
		Cells[0]->setStim(1);
	}
	
	//updating all neurons in simulation
	for (auto& cell: Cells)
	{
		cell->Neuron::Update(TimeStep, Time*TimeStep, Iext);  //need to convert back to time in double
	}
	
	return true;
}

void Simulation::Network()
{
	for(auto& cell:Cells)
	{	cell->AddNeighbors(Cells); }
}
