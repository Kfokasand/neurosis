#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include "relation.hpp"


using namespace std;


class Neuron{
	
	private:
//should the resistance capaciy and other variable be static, here all cells share the same but they could be different

		
	//personal variables which change with time
		double MembPot;
		double SpikeNumb;;
		vector<double> SpikeHistory;
		//implement delay in current reception
		vector<double> Buffer;
		//internal cell clock
		int CellTime;
		
	//personal variables which may change with time
		double Cap; //capacity
		double Res; //resistance
		double Tau; //I'm not sure
		ofstream history;
		
	//personal variables which stay constant once intialised

		const string Name;
		const double TauRef; // refractory perdiod
		const double Vres; //membrane potential after spike
		const double SpikeThreshold; //potential to trigger neuron spike
		vector<rel> neighbors_; 
		int delay_;
		
	//private methods
		
		//convert time into a buffer Index
		int Index(int time);

	public:


	//constructor provided with default values
		Neuron(string name);
		Neuron(const Neuron& other) = delete;
		~Neuron();

	//getters 
		double getMembPot() const;
		double getSpikeNumb() const ;
		double getTauRef() const;
		//returns the time value of the last spike in history
		double getLastSpike();

	//setters
		void setMembPot(double value);

	//cell dev methods
	
		//changes value of membrane potential according to time laps, external current or spikes
		//returns true if the cell Fires
		void Update(double TimeStep, double time, double Iext=0);
		//resets membrane potential to rest value
		void Reset();
		//the neuron Fires an action potentian and then resets
		void Fire(double time, double time_step);
		//Receive voltage from another neuron
		void Receive(double charge, int time); //use general time since both cells wright in time_%D Index of vector 
		//Send spike to all neighbors
		void Send();
		//add tab of cells into tab of neighbors
		void AddNeighbors(vector<Neuron*>& cells);

};



#endif
