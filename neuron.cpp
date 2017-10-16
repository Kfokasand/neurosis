#include "neuron.hpp"
#include <cmath>
#include <assert.h>


Neuron::Neuron(string name)
//double iMembPot=10, double iSpikeNumb=0, double t=20, double tref=2, double reset=10, double spiket=20
		:Name(name),MembPot(0), SpikeNumb(0), 
		 Cap(1), Tau(20),Stim(0),
		 TauRef(2), Vres(0), SpikeThreshold(20)
		{
			cout << "a neuron is born" << endl;
			cout << "initial membrane potential is : " << MembPot << endl;
			SpikeNumb=0;
			cout << "initial number of spikes is : " << SpikeNumb << endl;
			Res=20;
			
			//opening channel to store membrane potentials
			history.open("history" + name +".txt");
			cout << "channel history " +name + " has been opened" << endl;
			history << "Member potential for neuron " << name;

	
			//initialising cells own clock
			CellTime=0;
			Delay=1.5/0.1; //replace the 0.1 by time step but then need to dd in constructor
			//initialising buffer with all 0 values
			Buffer=(vector<double> (Delay+1,0));
		}

Neuron::~Neuron()
		{
			history.close();
			//comment liberer proprement la mémoire si plusieurs neurones pointent sur la mm cellule 
			/*for(auto& neighbor : Neighbors)
			{
				neighbor =delete; // va effacer le neurone -> c'est pas bien
				neighbor= nullptr;
			}*/
		}
//A DISCUTER
		
double Neuron::getMembPot() const
{
	return MembPot;
}

void Neuron::setMembPot(double value)
{
	MembPot=value;
}

double Neuron::getSpikeNumb() const 
{
	return SpikeNumb;
}


void Neuron::Update(double TimeStep, double time, double Iext)// time has been converted to appropriate double in calling of method
{
	double EXP1 (exp(-TimeStep/Tau));
	//checking the refractory period has passed since last spike 
	//or that there has been no spike yet
	if((!SpikeHistory.empty() and time>=getLastSpike()+TauRef) or SpikeHistory.empty()) 
	{
		if (Stim) {		MembPot= (MembPot*EXP1+Iext*Res*(1-EXP1)+Buffer[Index(CellTime)]); }
		else { MembPot= (MembPot*EXP1+Buffer[Index(CellTime)]); }

		if(MembPot>SpikeThreshold) // if the membrane potential crosses the threshold an action potential is Fired
		{
			Fire(time, TimeStep);
		}
		
	} 
	
	//if the neuron is still in its refractory period the membrane potential stays at reset value
	else if (!SpikeHistory.empty() and time<=getLastSpike()+TauRef)
	{ 
		Reset();
	}
	
			
	//storing membrane potential value in.txt file
	history  << " at time "<< time << " ms : " << MembPot << "\n" ;
	history << "Buffer values: \n";
	for(auto val : Buffer)
	{
		history << "||" << val;
	}
	history << "||";
	//resetting used buffer value
	Buffer[Index(CellTime)];
	//incrementing cell's clock
	CellTime+=1;
	
}

void Neuron::Reset()
{
	MembPot=Vres;
}


void Neuron::Fire(double time, double time_step)
{
	//incrementing number of spikes of particular neuron
	SpikeNumb+=1;
	//storing the time of the action potential
	SpikeHistory.push_back(time);
	
	//Sending voltage to all neighbor cells
	Send();
	//reseting membrane potential
	Reset();
	cout << Name << " neuron has Fired at " << time<< endl;
	history << "\n SPIKED at " << time <<"\n";
}

double Neuron::getLastSpike()
{
	return SpikeHistory[SpikeHistory.size()-1];
}

void Neuron::Receive(double charge, int time)
{
	assert(Index(time+Delay) < Buffer.size());
	Buffer[Index(time+Delay)]=charge;
	cout << "Stored " << charge << " in buffer" << endl;
}

void Neuron::Send()
{
	//cout << "entered Send " << endl;
	//go through all neighbors and call their Receive function with the right coeff
	if(Neighbors.empty()) {cout << "But there are no neighbors" << endl;}
	for(auto neighbor: Neighbors)
	{
		//cout << "I have sent something " << endl;
		neighbor.n->Receive(neighbor.J,CellTime);
	}
}

void Neuron::AddNeighbors(vector<Neuron*>& cells)
{

	if(cells.empty()){ cout << "argument vector is empty though" << endl;}
	for(auto& cell: cells)
	{
		//cout << "entered adding neighbors " << endl;
		rel* blip = new rel {cell,0.1};
		Neighbors.push_back(*blip);
	}
	cout << "cell has " <<Neighbors.size() << " neighbors" << endl;
}

int Neuron::Index(int time)
{
	return time%Delay;
}

void Neuron::setStim(bool stim)
{
	Stim=stim;
}
