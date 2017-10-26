#ifndef NETWORK_H
#define NETWORK_H

using namespace std; 

class Network {

private:

	//variables to be held by network 
	const int N; //number of wanted cells in simulation
	static const int Ne; //number of wanted exitatory cells or prop ?
	static const int Ni; //number of wanted inhibitory cells or prop ?
	static const int Ce; //number of excitatory connections on a cell
	static const int Ci; //number of inhibitory connections on a cell
	static const int Cext; //number of external connections on a cell
	const double Je; //excitatory coefficient
	const double Ji; //inhibitory coefficient


	//constuctor of Network receives number of wanted cells

	Network(int n) :
	N(n),
	Ne(n*0.1),
	Ni(n*0.0250),
	Ce(Ne*0.1),
	Ci(Ni*0.1),
	Cext(Ce),
	Je(0.1),
	Ji(0,5)
	{
		CreateNeurons(N);
		LinkNetwork();
	}

public:

	void CreateNeurons(int n); //adds a neuron to the network
	void LinkNetwork(); //creates lins betyseen neurons
	void UpdateNetwork(); //calls update of all neurons in network
	void StoreState(); //stores mb of all cells at a given step

};

#endif
