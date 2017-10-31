#ifndef SIMULATION_H
#define SIMULATION_H
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
	Network* network;
	
	
	void SetSimTime();
	void SetCurrent();
	
	public:
	
	/*
	* a constructor, takes no arguments
	*/
	Simulation();
	
	/*
	*runs the simulation by calling Network's update methodand increments the simulation time with each step
	*/
	void Run();
	
	/*
	*takes time value in steps and converts it to ms
	* @param double (int) time in steps
	* @return double time in ms
	*/
	double RealTime(double time);
	
	/*
	* writes membrane potential of all cells into a file at a given time
	*/
	void StoreState();
	

};

#endif
