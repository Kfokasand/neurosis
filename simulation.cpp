#include "simulation.hpp"
#include <array>
#include <list>

Simulation::Simulation(double timestep)
			:H(timestep),StepTime(0)
			{ 	cout<< "You are intialising a simulation" << endl <<"Please enter settings" <<endl;
				SetSimTime();
				int n;
				cout << "Enter number of desired neurons in network : " ;
				cin >> n;
				network = new Network(n,H);
				SetCurrent();	
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

void Simulation::Run()
{

	//opening channel to store membrane potentials
	ofstream history;
	history.open("history.txt");	
	
	//updating cell
	do{
		network.Network::UpdateNetwork(Iext);
		StoreState();
		//incremeting simulation Time in steps
		StepTime+=1;
	}
	while(RealTime(StepTime)< SimTime); //checking if simulation has reached it's end in ms	
}


double Simulation::RealTime(double time)
{
	return time*H;
}

void Simulation::StoreState()
{
	vector<double> state (network.Network::StoreState());
	for(unsigned int i(0); i< state.size(); ++i)
	{
		history << //:TODO joli tableau +temps +history as attribute + gerer Network as attribute (intialisation dyn ?)
	}
}
