#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>

using namespace std;


class Neuron{
	
	private:
//should the resistance capaciy and other variable be static, here all cells share the same but thez could be different

	//step of time for simulation
		//static double TimeStep;
	//counting created neurons
		static int cellCount;
	//personal variables which change with time
		double MembPot;
		double SpikeNumb;;
		//vector<double> SpikeHistory;
	//are general but could be personalised
		double Res;
		double Cap;
		double Tau;
		double TauRef;
		double resetValue;
		double SpikeThreshold;

//use a separate file for constants ?

	public:


	//constructor provided with default values
		Neuron(double iMembPot=0, double iSpikeNumb=0, double t=10, double tref=2, double reset=-70, double spiket=70)
		:MembPot(iMembPot), SpikeNumb(iSpikeNumb), Tau(t), TauRef(tref), resetValue(reset), SpikeThreshold(spiket)
		{
			cellCount++;
		}

		double getMembPot() const;
		void setMembPot();
		double getSpikeNumb() const ;
		vector<double>& getSpikeHistory() const ;
		void update(double Iext, double TimeStep);
		void resetMembPot();
		void fire();
		void printMembPot();
		
		


};

#endif
