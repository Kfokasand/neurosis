#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Neuron{
	
	private:
//should the resistance capaciy and other variable be static, here all cells share the same but thez could be different

		
	//counting created neurons 
		static int cellCount;

		
	//personal variables which change with time
		double MembPot;
		double SpikeNumb;;
		vector<double> SpikeHistory;
		
		
	//personal variables which stay constant once intialised, think yhich ones are static double or const doubles
		
		double Res; //resistance
		double Cap; //capacity
		double Tau;
		double TauRef; // refractory perdiod
		double Vres; //membrane potential after spike
		double SpikeThreshold; //potential to trigger neuron spike

//use a separate file for constants ?

	public:


	//constructor provided with default values
		Neuron(double iMembPot=0, double iSpikeNumb=0, double t=20, double tref=2, double reset=10, double spiket=20)
		:MembPot(iMembPot), SpikeNumb(iSpikeNumb), Tau(t), TauRef(tref), Vres(reset), SpikeThreshold(spiket)
		{
			cout << "a neuron is born" << endl;
			cellCount++;
		}
		
	//getters 
		double getMembPot() const;
		double getSpikeNumb() const ;
		vector<double>& getSpikeHistory() const ;
		double getTauRef() const;
		double getLastSpike();
		
	//setters
		void setMembPot();

	//cell dev methods
		void update(double TimeStep, double time, double Iext=0);
		void resetMembPot();
		void fire(double time);

	
	//printing methods
		
	//storing history in main to have time component
		//void storeMembPot();
		

};
#endif
