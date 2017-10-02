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

void Neuron::update(double Iext, double TimeStep)
{
	MembPot= MembPot*exp(-Tau/TimeStep)+Iext*Cap*Tau*(1-exp(-Tau/TimeStep));
	
	if(MembPot>SpikeThreshold)
	{
		fire();
	}
	
}

void Neuron::resetMembPot()
{
	MembPot=Vres;
}

//the neuron fires an action potentian and the resets
void Neuron::fire()
{
	resetMembPot();
	SpikeNumb+=1;
	cout << "a neuron has fired" << endl;
}

void Neuron::printMembPot()
{
	cout << MembPot;
}

