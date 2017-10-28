#ifndef NETWORK_H
#define NETWORK_H

using namespace std; 

class Network {

private:

	//variables to be held by network 
	const int N; //number of wanted cells in simulation
	 const int Ne; //number of wanted exitatory cells or prop ?
	 const int Ni; //number of wanted inhibitory cells or prop ?
	 const int Ce; //number of excitatory connections on a cell
	 const int Ci; //number of inhibitory connections on a cell
	 const int Cext; //number of external connections on a cell
	const double Je; //excitatory coefficient
	const double Ji; //inhibitory coefficient
	const double H; //timeStep given by simulation

	//table of cells
	vector<Neuron*> Cells; //stores the created neurons


public:

	//constuctor of Network receives number of wanted cells
	Network(int n, double h);
	~Network();
	
	void CreateNeurons(int n); //adds a neuron to the network
	void LinkNetwork(); //creates links between neurons
	void UpdateNetwork(double Iext_); //calls update of all neurons in network
};

#endif
