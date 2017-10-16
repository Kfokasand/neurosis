#ifndef SIM_H
#define SIM_H
#include "neuron.hpp"

using namespace std;

class Simulation{

	private :
	
	//simulation constants

//given by main
	double TimeStep;
//given by user
	double SimTime;
	double Iext;
	//time boundaries for external current application
	double abound;
	double bbound;

	//simulation variables
	int Time; // is counted as increments of the timestep
	vector<Neuron*> Cells; //stores the created neurons
	
	
	void SetSimTime();
	void SetCurrent();
	
	public:
	
	Simulation(double timestep, int time=0);
	~Simulation();
	void Run();
	void NewNeuron(string name);
	//chosen as a bool to ensure all neurons have been succesfully updated at each step (test may be done with a catch and throw or asset
	
	bool NeuronsUpdate();
	void Network();


};

#endif
