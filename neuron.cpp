#include "neuron.hpp"
#include <cmath>


Neuron::Neuron(double iMembPot, double iSpikeNumb, double t, double tref, double reset, double spiket)
		:MembPot(iMembPot), SpikeNumb(iSpikeNumb), 
		 Cap(reset), Tau(t),
		 TauRef(tref), Vres(reset), SpikeThreshold(spiket)
		{
			cout << "a neuron is born" << endl;
			cout << "initial membrane potential is : " << MembPot << endl;
			SpikeNumb=0;
			cout << "initial number of spikes is : " << SpikeNumb << endl;
			Res=Tau/Cap;
		}
		
double Neuron::getMembPot() const
{
	return MembPot;
}

void Neuron::setMembPot()
{}

double Neuron::getSpikeNumb() const 
{
	return SpikeNumb;
}


void Neuron::update(double TimeStep, double time, double Iext)// time has been converted to appropriate double in calling of method
{
	double EXP1 (exp(-TimeStep/Tau));
	
	//checking the refractory period has passed since last spike 
	//or that there has been no spike yet
	if((!SpikeHistory.empty() and time>=getLastSpike()+TauRef) or SpikeHistory.empty()) 
	{
		MembPot= MembPot*EXP1+Iext*Res*(1-EXP1);

		if(MembPot>SpikeThreshold) // if the membrane potential crosses the threshold an action potential is fired
		{
			fire(time);
		}
	} 
	
	//if the neuron is still in its refractory period the membrane potential stays at reset value
	else if (!SpikeHistory.empty() and time<=getLastSpike()+TauRef)
	{ 
		resetMembPot();
	}
	
}

void Neuron::resetMembPot()
{
	MembPot=Vres;
}


void Neuron::fire(double time)
{
	//incrementing number of spikes of particular neuron
	SpikeNumb+=1;
	//storing the time of the action potential
	SpikeHistory.push_back(time);
	//reseting membrane potential
	resetMembPot();
	cout << "a neuron has fired" << endl;

}


double Neuron::getLastSpike()
{
	return SpikeHistory[SpikeHistory.size()-1];
}

