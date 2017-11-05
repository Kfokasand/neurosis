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
	double progress(0);
	double barwidth(70);
	//updating cell
	do{
		network->Network::UpdateNetwork(Iext,StepTime);
		//incremeting simulation Time in steps
		StepTime+=1;
		
		int pos(progress*barwidth/SimTime*H);
		cout << "[";
		for (int c(0); c< barwidth; c++)
		{
			if (c<=pos)
			{
				cout << "#";
			}
				else { cout << "-" ;}
		}
			progress+=1.0;
			cout << "]";
			
			cout << progress/SimTime*H *100 << "%\r" ;
			cout.flush();
	}
	while(RealTime(StepTime)< SimTime); //checking if simulation has reached it's end in ms	
	cout << endl << "Simulation finished" << endl;
}


double Simulation::RealTime(int time) const
{
	return time*H;
}


