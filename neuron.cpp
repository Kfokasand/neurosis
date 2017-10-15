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
			//initialising cells own clock
			cell_time=0;
			delay_=1.5/0.1; //replace the 0.1 by time step but then need to dd in constructor
			//initialising buffer with all 0 values
			buffer_=(vector<double> (delay_,0));
		}

/*Neuron::~Neuron()
		{
			//comment liberer proprement la mémoire si plusieurs neurones pointent sur la mm cellule 
			for(auto& neighbor : neighbors_)
			{
				neighbor =delete; // va effacer le neurone -> c'est pas bien
				neighbor= nullptr;
			}
		}
*/ //A DISCUTER
		
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
	
	//incrementing cell's clock
	cell_time+=1;
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
	
	//sending voltage to all neighbor cells
	send(MembPot);
	//reseting membrane potential
	resetMembPot();
	//cout << "a neuron has fired" << endl;

}

double Neuron::getLastSpike()
{
	return SpikeHistory[SpikeHistory.size()-1];
}

void Neuron::recieve(double charge, int time)
{
	buffer_[time%delay_]=charge;
	//cout << "I have received something" << endl;
}

void Neuron::send(double charge)
{
	//cout << "entered send " << endl;
	//go through all neighbors and call their recieve function with the right coeff
	if(neighbors_.empty()) {cout << "But there are no neighbors" << endl;}
	for(auto neighbor:neighbors_)
	{
		//cout << "I have sent something " << endl;
		neighbor.n->recieve(charge, cell_time);
	}
}

void Neuron::add_neighbors(vector<Neuron*>& cells)
{

	if(cells.empty()){ cout << "argument vector is empty though" << endl;}
	for(auto& cell: cells)
	{
		//cout << "entered adding neighbors " << endl;
		rel* blip = new rel {cell,1.0};
		neighbors_.push_back(*blip);
	}
	cout << "cell has " <<neighbors_.size() << " neighbors" << endl;
}

