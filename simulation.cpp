#include "simulation.hpp"
#include <fstream>

Simulation::Simulation(double timestep, int time)
			:time_step(timestep), time_(time)
			{ 	cout<< "You are intialising a simulation" << endl <<"Please enter settings" <<endl;
				set_sim_time();
				set_current();	
			}


void Simulation::set_sim_time()
{

	//check the imput
	do {
		cout << endl << "Set simulation time in ms : ";
		cin>> sim_time;	
	} while(sim_time<0);
	
	/*if (!cin) // same as cin.fail() checking value type
	{
		cin.clear();
		cin.ignore(1000);
		cout << "Invalid value type, please enter value again : " ;
	}*/
}



void Simulation::set_current()
{
	//check the imput
	cout<< "Set value of external current :";
	cin>>Iext;
	cout << "Set time limits : a=";
	cin>>abound;
	cout << "b=";
	cin>>bbound;
}

void Simulation::new_neuron()
{
	Neuron* n1 = new Neuron ();
	cells_.push_back(*n1); // creating a dynamic neuron avoid copies
	// for now all cells are neigbors
}

void Simulation::run()
{
	new_neuron();
	new_neuron();
	network();
	//opening channel to store membrane potentials
	ofstream history;
	history.open("history.txt");	
	
	//updating cell
	do{
		neurons_update(history);
		
		//incremeting simulation time_
		time_+=1;
	}
	while(time_*time_step< sim_time);

	cout << time_*time_step << endl;
	
	cout << "The neuron has fired " << cells_[0].Neuron::getSpikeNumb() << " times" <<endl;
	
}



bool Simulation::neurons_update(ofstream& out)
{
	//updating all neurons in simulation
	for (auto& neuron : cells_)
	{
		//when an external current is applied
		if(time_*time_step>abound and time_*time_step< bbound)
		{
			neuron.Neuron::update(time_step, time_*time_step, Iext);  //need to convert back to time in double
		} 
		//when no external current is applied
		else {
			neuron.Neuron::update(time_step, time_*time_step);
		}
		
		//storing membrane potential value in.txt file
		out << neuron.getMembPot() << " " ;
	}

	
	return true;
}

void Simulation::network()
{
	for(auto cell:cells_)
	{	cell.add_neighbors(cells_); }
}
