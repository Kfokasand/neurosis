#include "neuron.hpp"

#include <cmath>

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

/*vector<double>& Neuron::getSpikeHistory() const 
{
	return SpikeHistory;
}*/

void Neuron::update(double TimeStep, double time, double Iext)
{
	if(!SpikeHistory.empty() and time<getLastSpike()+TauRef) //checking the refractory perdiod has passed since last spike
	{
		MembPot= MembPot*exp(-Tau/TimeStep)+Iext*Cap*Tau*(1-exp(-Tau/TimeStep));
		
		if(MembPot>SpikeThreshold) // if the membrane potential crosses the threshold an action potential is fired
		{
			fire(time);
		}
	} 
	else if (SpikeHistory.empty())
	{
			MembPot= MembPot*exp(-Tau/TimeStep)+Iext*Cap*Tau*(1-exp(-Tau/TimeStep));
		
		if(MembPot>SpikeThreshold) // if the membrane potential crosses the threshold an action potential is fired
		{
			fire(time);
		}
	}
	else if (!SpikeHistory.empty() and time>=getLastSpike()+TauRef)
	{ //if the neuron is still in its refractory period the membrane potential stays at reset value
		
		resetMembPot();
	}
	
}

void Neuron::resetMembPot()
{
	MembPot=Vres;
}

//the neuron fires an action potentian and the resets
void Neuron::fire(double time)

{
	resetMembPot();
	SpikeNumb+=1;
	cout << "a neuron has fired" << endl;
	SpikeHistory.push_back(time);
}



double Neuron::getLastSpike()
{
	return SpikeHistory[SpikeHistory.size()-1];
}

}

void Neuron::printMembPot()
{
	cout << MembPot;
}
