#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct rel
{
	Neuron* n;
	double quality_coeff;
	
};

class Neuron{
	
	private:
//should the resistance capaciy and other variable be static, here all cells share the same but they could be different

		
	//personal variables which change with time
		double MembPot;
		double SpikeNumb;;
		vector<double> SpikeHistory;
		//implement delay in current reception
		vector<double> buffer_;
		//internal cell clock
		int cell_time;
		
		
	//personal variables which may change with time
		double Cap; //capacity
		double Res; //resistance
		double Tau; //I'm not sure
		
	//personal variables which stay constant once intialised

		double TauRef; // refractory perdiod
		double Vres; //membrane potential after spike
		double SpikeThreshold; //potential to trigger neuron spike
		vector<rel> neighbors;
		int delay_;

	public:


	//constructor provided with default values
		Neuron(double iMembPot=10, double iSpikeNumb=0, double t=20, double tref=2, double reset=10, double spiket=20);

	//getters 
		double getMembPot() const;
		double getSpikeNumb() const ;
		double getTauRef() const;
		//returns the time value of the last spike in history
		double getLastSpike();

		
	//setters
		void setMembPot();

	//cell dev methods
	
		//changes value of membrane potential according to time laps, external current or spikes
		void update(double TimeStep, double time, double Iext=0);
		//resets membrane potential to rest value
		void resetMembPot();
		//the neuron fires an action potentian and then resets
		void fire(double time);
		//recieve voltage from another neuron
		void recieve(double charge, int time); //use general time since both cells wright in time_%D index of vector 
		//send spike to all neighbors
		void send(double charge);

		
	//storing history in main to have time component
		//void storeMembPot();
		

};



#endif
