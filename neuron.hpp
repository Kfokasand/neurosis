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
		

		double Cap; //capacity
		double Res; //resistance
		double Tau; //I'm not sure
		bool Stim; //Idicates if neuron recieves programmed external current
		
		const double TauRef; // refractory period
		const double Vres; //membrane potential after spike
		const double SpikeThreshold; //potential to trigger neuron spike
		const unsigned int Delay; //delay in steps for current to arrive
		const bool Excitatory;
		
	//private methods
		
		//convert time into a buffer Index
		unsigned int Index(unsigned int time);

	public:

	/**
	 * Neuron constructor 
	 *@param bool indicating neuron type true = excitatory false=inhibitory
	 * copy of Neurons is blocked
	 */
		Neuron(bool ex);
		Neuron(const Neuron& other) = delete;

	//getters 
	/**
	 * takes no arguments
	 * @return current Membrane Potential
	 */
	  
		double getMembPot() const;
	/**
	 * takes no arguments
	 * @return number of recorded spikes
	 */
		double getSpikeNumb() const ;
	/**
	 * takes no arguments
	 * @return time (in real time: ms) of last recorded spike
	 */
		double getLastSpike() const;

	//setters
		void setMembPot(double value);
		void setStim(bool stim);

	//cell dev methods
	/**
	 * stores cellTime converted into RealTime (ms) into SpikeHistory
	 * @param double H: simulation time step
	 */
		void storeSpikeTime(double H);
	/**
	 *changes value of membrane potential according to time laps, external current or spikes
	 * @param double H: simulation time step
	 * @return true if cells fires during current step
	 */
		bool UpdateNeuron(double H, double Iext);
		//resets membrane potential to rest value
		void Reset();
		//the neuron Fires an action potentian and then resets
		void Fire(double H);
		//Receive voltage from another neuron
		void Receive(double charge, unsigned int time); //use general time since both cells wright in time_%D Index of vector 


};

#endif
