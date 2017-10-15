#include "simulation.hpp"


Simulation::Simulation(double timestep, int time)
			:time_step(timestep), time_(time)
			{ 	cout<< "You are intialising a simulation" << endl <<"Please enter settings" <<endl;
				set_sim_time();
				set_current();	
			}

Simulation::~Simulation()
			{
				for(auto& cell: cells_)
				{
					delete cell;
					cell=nullptr;
				}
				
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

void Simulation::new_neuron(string name)
{
	Neuron* n1 = new Neuron (name);
	/*'doesn't like it, copies are created!! how to avoid it ?'*/
	cells_.push_back(n1); // creating a dynamic neuron avoid copies
	// for now all cells are neigbors
}

void Simulation::run()
{
	new_neuron("n1");
	new_neuron("n2");
	cells_[1]->setMembPot(0);
	network();
	//opening channel to store membrane potentials
	ofstream history;
	history.open("history.txt");	
	
	//updating cell
	do{
		neurons_update();
		
		//incremeting simulation time_
		time_+=1;
	}
	while(time_*time_step< sim_time);

	cout << time_*time_step << endl;
	
	cout << "Neuron 1 has fired " << cells_[0]->Neuron::getSpikeNumb() << " times" <<endl;
	cout << "Neuron 2 has fired " << cells_[1]->Neuron::getSpikeNumb() << " times" <<endl;
	
}



bool Simulation::neurons_update()
{
	//updating all neurons in simulation
	for (auto& cell: cells_)
	{
		//when an external current is applied
		if(time_*time_step>abound and time_*time_step< bbound)
		{

			cell->Neuron::update(time_step, time_*time_step, Iext);  //need to convert back to time in double
		} 
		//when no external current is applied
		else {
			cell->Neuron::update(time_step, time_*time_step);
		}
	}
	
	return true;
}

void Simulation::network()
{
	for(auto& cell:cells_)
	{	cell->add_neighbors(cells_); }
}
