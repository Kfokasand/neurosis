#ifndef SIM_H
#define SIM_H
#include "network.hpp"

using namespace std;

class Simulation{

	private :
	
	//simulation constants

//given by main
	double H; // time step per cycle of simulation
//given by user
	double SimTime;
	double Iext;
	//time boundaries for external current application
	double abound;
	double bbound;

	//simulation variables
	unsigned int StepTime; // is counted as increments of the timestep H
	Network network;
	
	
	void SetSimTime();
	void SetCurrent();
	
	public:
	
	Simulation(double timestep);
	void Run();
	double RealTime(double time);
	void StoreState();
	

};

#endif
