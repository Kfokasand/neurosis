#include "network.hpp"
#include <cstdlib>

Network::Network(int n, double h)
	:N(n),
	Ne(n*0.1),
	Ni(n*0.0250),
	Ce(Ne*0.1),
	Ci(Ni*0.1),
	Cext(Ce),
	Je(0.1),
	Ji(0.5),
	H(h)
	{
		Connections = vector<vector<int>> (N, vector<int> (N,0)); //matrix of size N*N filled with 0 values
		CreateNeurons(N);
		LinkNetwork();
	}

Network::~Network()
{
	for(auto& cell: Cells)
	{
		delete cell;
		cell=nullptr;
	}
}

void Network::CreateNeurons(int n)
{
	for(int i(1); i<=n; ++i)
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
			Connections[i][j]+=1; //means ith neuron is affected by jth neuron
		}
	//has to recieve Ci connections from neurons in the Last Ni	
		for(int c(0); c<Ci; ++c)
		{
			j=rand()%Ni +Ne; //random int in [Ne, Ne+Ni-1]
			Connections[i][j]+=1;
		}

	}
}

void Network::UpdateNetwork(double Iext_)
{
		//updating all neurons in simulation
	for (auto& cell: Cells)
	{
		if(cell->Neuron::UpdateNeuron(H, Iext_))
		{
			//gerer la somme puis l'envoi des potentiels
		}
	}
}
