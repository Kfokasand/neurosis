#include "simulation.hpp"
#include "network.hpp"
#include <array>
#include <list>

Simulation::Simulation(double timestep)
			:H(timestep),StepTime(0)
			{ 	cout<< "You are intialising a simulation" << endl <<"Please enter settings" <<endl;
				SetSimTime();
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
	int n;
	cout << "Enter number of desired neurons in network : " ;
	cin >> n;
	Network network (n,H);
	//opening channel to store membrane potentials
	ofstream history;
	history.open("history.txt");	
	
	//updating cell
	do{
		network.Network::UpdateNetwork(Iext);
		//incremeting simulation Time in steps
		StepTime+=1;
	}
	while(RealTime(StepTime)< SimTime); //checking if simulation has reached it's end in ms
	
	
}


void Simulation::NeuronsUpdate()
{
	//allows to stimulate only one neuron in network
	if(RealTime(StepTime)>abound and RealTime(StepTime)< bbound) //checking time is in stimulation bounds in ms
	{
	}
	


}


double Simulation::RealTime(double time)
{
	return time*H;
}
