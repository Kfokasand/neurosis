#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>

using namespace std;


class Neuron{
	
	private:
//should the resistance capaciy and other variable be static, here all cells share the same but thez could be different

		
	//counting created neurons
		static int cellCount;
		
	//personal variables which change with time
		double MembPot;
		double SpikeNumb;;
		//vector<double> SpikeHistory;
		
		
	//personal variables which stay constant once intialised
		
		double Res; //resistance
		double Cap; //capacity
		double Tau;
		double TauRef; // refractory perdio
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
		
	//setters
		void setMembPot();

	//cell dev methods
		void update(double Iext, double TimeStep);
		void resetMembPot();
		void fire();
	
	//printing methods
		void printMembPot();
		
		


};

#endif
