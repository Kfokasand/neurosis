#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;


class Neuron{
	
	private:
//should the resistance capaciy and other variable be static, here all cells share the same but they could be different

		
	//personal variables which change with time
		double MembPot;
		double SpikeNumb;;
		vector<double> SpikeHistory;
		
		
	//personal variables which may change with time
		double Cap; //capacity
		double Res; //resistance
		double Tau; //I'm not sure
		ofstream history;
		
	//personal variables which stay constant once intialised

		double TauRef; // refractory perdiod
		double Vres; //membrane potential after spike
		double SpikeThreshold; //potential to trigger neuron spike


	public:


	//constructor provided with default values
		Neuron(string name, double iMembPot=10, double iSpikeNumb=0, double t=20, double tref=2, double reset=10, double spiket=20);
	//copy constuctor to handle flow
		Neuron(const Neuron& other);
		
	//destructor meant to close flow to hsitory file
		~Neuron();

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
		//returns true if the cell fires
		bool update(double TimeStep, double time, double Iext=0);
		//resets membrane potential to rest value
		void resetMembPot();
		//the neuron fires an action potentian and then resets
		void fire(double time);
		//the neuron received an action potential
		void receive();

		
	//storing history in main to have time component
		//void storeMembPot();
		

};

#endif
