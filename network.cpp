#include "network.hpp"
#include <cstdlib>

Network::Network(int n)
	:N(n),
	Ne(n*0.1),
	Ni(n*0.0250),
	Ce(Ne*0.1),
	Ci(Ni*0.1),
	Cext(Ce),
	Je(0.1),
	Ji(-0.5),
	H(0.1)
	{
		Connections = vector<vector<int>> (N, vector<int> (N,0)); //matrix of size N*N filled with 0 values
		CreateNeurons();
		LinkNetwork();
		
		//opening channel to store membrane potentials
		history.open("history.txt");
	}

Network::~Network()
{
	for(auto& cell: Cells)
	{
		history.close();
		delete cell;
		cell=nullptr;
	}
}

void Network::CreateNeurons()
{
	for(int i(1); i<=N; ++i)
		{	
			if (i<=Ne ) {Cells.push_back(new Neuron(1));} //makes Ne excitatory neurons
			else {Cells.push_back(new Neuron(0));} //the rest N-Ne are inhibitory
		};
}

void Network::LinkNetwork()
{
	int j;
	//for every daughter (receiver) neuron in the simulation
	for(unsigned int i(0); i<Connections[0].size(); ++i)
	{
	//has to recieve Ce connections from neurons in the first Ne
		for(int c(0); c<Ce; ++c)
		{
			j=rand()%Ne; //random int in [0, Ne-1]
			Connections[j].push_back(i); //means ith neuron is affected by jth neuron
		}
	//has to recieve Ci connections from neurons in the Last Ni	
		for(int c(0); c<Ci; ++c)
		{
			j=rand()%Ni +Ne; //random int in [Ne, Ne+Ni-1]
			Connections[j].push_back(i);
		}
	}
}

void Network::UpdateNetwork(double Iext_, unsigned int time)
{
	//updating all neurons in simulation
	for (unsigned int i(0); i<Cells.size(); ++i)
	{
		if(Cells[i]->Neuron::UpdateNeuron(H, Iext_))
		{
			StoreSpike(Cells[i],i);
			for(auto& daughter_index : Connections[i])
			{
				if(Cells[i]->isEx())
				{
					Cells[daughter_index]->Receive(Je, time);
					
				} else {
					
					Cells[daughter_index]->Receive(Ji, time);
				}
			}
		}
	}
}

vector<double> Network::StoreState() const
{
	vector<double> state;
	for(auto cell:Cells)
	{
		state.push_back(cell->getMembPot());
	}
	
	return state;	
}

void Network::StoreSpike(Neuron* n, unsigned int i) const
{
	history << n->getLastSpike() << "\t" << i << "\n"; 
}
