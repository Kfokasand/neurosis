#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Neuron{
	
	private:
//should the resistance capaciy and other variable be static, here all cells share the same but they could be different
		

	//counting created neurons 
		static int cellCount;

		
	//personal variables which change with time
		double MembPot;
		double SpikeNumb;;
		vector<double> SpikeHistory;
		
		
	//personal variables which stay constant once intialised, think yhich ones are static double or const doubles
		
		
	//personal variables which stay constant once intialised
		
		double Cap; //capacity
		double Res; //resistance
		double Tau;

		double TauRef; // refractory perdiod
		double Vres; //membrane potential after spike
		double SpikeThreshold; //potential to trigger neuron spike


	public:


	//constructor provided with default values
		Neuron(double iMembPot=10, double iSpikeNumb=0, double t=20, double tref=2, double reset=10, double spiket=20)
		:Cap(reset), MembPot(iMembPot), SpikeNumb(iSpikeNumb), Tau(t), TauRef(tref), Vres(reset), SpikeThreshold(spiket)
		{
			cout << "a neuron is born" << endl;
			cellCount++;
			cout << "initial membrane potential is : " << MembPot << endl;
			Res=Tau/Cap; //stays constant at this may change later
		}

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

		
	//storing history in main to have time component
		//void storeMembPot();
		

};

#endif
