#ifndef NETWORK_H
#define NETWORK_H
#include "neuron.hpp"
using namespace std; 

class Network {

private:

	//variables to be held by network 
	const int N; ///< number of wanted cells in simulation
	 const int Ne; ///< number of wanted exitatory cells or prop ?
	 const int Ni; ///< number of wanted inhibitory cells or prop ?
	 const int Ce; ///< number of excitatory connections on a cell
	 const int Ci; ///< number of inhibitory connections on a cell
	 const int Cext; ///< number of external connections on a cell
	const double Je; ///< excitatory coefficient
	const double Ji; ///< inhibitory coefficient
	const double H; ///< timeStep given by simulation


	vector<Neuron*> Cells; ///< table with references to all neurons
	vector<vector<int>> Connections; ///< stores connections in network as ints
	
	ofstream history; ///< chanel data storage document
	
		
	/**
	 * Creates N Neurons, stores their ref in Cells
	 */
	void CreateNeurons(); 
	
	/**
	 * Creates links between Neurons and stores them in Connections
	 */
	void LinkNetwork();


public:

	/**
	 * Constructor
	 * @param int number of desires Neurons
	 * @param double h simulation time step
	 */
	Network(int n);
	
	/**
	 * Network copy has been blocked
	 */
	Network(Network& other)=delete;
	~Network();

	/**
	 * Calls update method of all Neurons and handles potential transmission
	 */
	void UpdateNetwork(double Iext_, unsigned int time);
	
	/**
	 * stores the membrane potential of all Neurons contained in Network in a vector
	 * @return returns vector of potentials (double)
	 */
	vector<double> StoreState() const;
	
	/**
	 *stores spike time in a document associated with Neuron Id
	 */
	 
	 void StoreSpike(Neuron* n, unsigned int i) const;
};

#endif
