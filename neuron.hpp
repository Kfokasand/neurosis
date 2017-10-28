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
		double SpikeNumb;
		vector<double> SpikeHistory;
		//implement delay in current reception
		vector<double> Buffer;
		//internal cell clock counted as increments of H
		unsigned int CellTime;
		
	//personal variables which may change with time
		double Cap; //capacity
		double Res; //resistance
		double Tau; //I'm not sure
		bool Stim;
		
	//personal variables which stay constant once intialised
		const double TauRef; // refractory period
		const double Vres; //membrane potential after spike
		const double SpikeThreshold; //potential to trigger neuron spike
		const unsigned int Delay;
		
	//private methods
		
		//convert time into a buffer Index
		unsigned int Index(unsigned int time);

	public:


	//constructor provided with default values
		Neuron();
		Neuron(const Neuron& other) = delete;
		~Neuron();

	//getters 
		double getMembPot() const;
		double getSpikeNumb() const ;
		//returns the time value of the last spike in history
		double getLastSpike() const;

	//setters
		void setMembPot(double value);
		void setStim(bool stim);

	//cell dev methods
		//stores time value when called into SpikeHistory, using cellTime converted into RealTime with H=TimeStep
		void storeSpikeTime(double H);
	
		//changes value of membrane potential according to time laps, external current or spikes
		//returns true if the cell Fires
		bool UpdateNeuron(double H, double Iext);
		//resets membrane potential to rest value
		void Reset();
		//the neuron Fires an action potentian and then resets
		void Fire(double H);
		//Receive voltage from another neuron
		void Receive(double charge, unsigned int time); //use general time since both cells wright in time_%D Index of vector 


};

#endif
