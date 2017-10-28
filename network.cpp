#include "network.hpp"
#include "neuron.hpp"

Network::Network(int n, double h)
	:N(n),
	Ne(n*0.1),
	Ni(n*0.0250),
	Ce(Ne*0.1),
	Ci(Ni*0.1),
	Cext(Ce),
	Je(0.1),
	Ji(0,5),
	H(h)
	{
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

void Neuron::CreateNeurons(int n)
{
	for(int i(1); i<=n, ++i)
		{Cells.push_back(new Neuron())};
}

void LinkNetwork()
{

}

void UpdateNetwork(double Iext_)
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