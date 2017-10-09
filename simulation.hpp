#ifndef SIM_H
#define SIM_H
#include <iostream>
#include <vector>
#include "neuron.hpp"


using namespace std;

class Simulation{

	private :
	
	//simulation constants

//given by main
	double time_step;
//given by user
	double sim_time;
	double Iext;
	//time boundaries for external current application
	double abound;
	double bbound;

	//simulation variables
	int time_; // is counted as increments of the timestep
	vector<Neuron> cells_; //stores the created neurons
	
	
	void set_sim_time();
	void set_current();
	
	public:
	
	Simulation(double timestep, int time=0);
	void run();
	void new_neuron();
	//chosen as a bool to ensure all neurons have been succesfully updated at each step (test may be done with a catch and throw or asset
	bool neurons_update(ofstream& out);



};

#endif
