#include "simulation.hpp"
#include <array>
#include <list>

Simulation::Simulation(double sim_time)
			:H(0.1),
			SimTime(sim_time),
			StepTime(0)
			{
	
					double je;
					double ji;
					double med;
					
					cout << "weight of excitation: ";
					cin>> je;
					
					cout << "weight of inhibition: ";
					cin>> ji;
					
					cout << "vext/vthr :";
					cin>> med;
					
					network = new Network(je,ji,med);
					
			}
			
Simulation::Simulation()
			:H(0.1),
			SimTime(1000),
			StepTime(0)
{
	network = new Network();
	
}
			
Simulation::~Simulation()
{
	delete network;
	network = nullptr;
}

void Simulation::SetSimTime()
{
	do {
		cout << endl << "Set simulation time in ms : ";
		cin>> SimTime;	
	} while(SimTime<0);

}



void Simulation::SetCurrent(double a, double b, double I)
{
	abound=a;
	bbound=b;
	Iext=I;
}

void Simulation::Run()
{
	
	//updating cell
	do{
		network->Network::UpdateNetwork(Iext,StepTime);
		//incremeting simulation Time in steps
		StepTime+=1;
	}
	while(RealTime(StepTime)< SimTime); //checking if simulation has reached it's end in ms	
	cout << "Simulation finished" << endl;
}


double Simulation::RealTime(double time) const
{
	return time*H;
}

void Simulation::StoreState()
{
	vector<double> state (network->Network::StoreState());
	for(unsigned int i(0); i< state.size(); ++i)
	{
		//:TODO joli tableau +temps +history as attribute + gerer Network as attribute (intialisation dyn ?)
	}
}

