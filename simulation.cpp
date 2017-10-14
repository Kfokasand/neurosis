#include "simulation.hpp"


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

void Simulation::new_neuron(string name)
{
	Neuron n1(name);
	cout << "you've constructed a neuron " << endl;
	cells_.push_back(n1);
	cout << "you've stored a neuron " << endl;
}

void Simulation::run()
{
	new_neuron("1");
	//new_neuron("2");
	cout << "you've been here " << endl;	
	
	//updating cell
	do{
		neurons_update();
		
		//incremeting simulation time_
		time_+=1;
	}
	while(time_*time_step< sim_time);

	cout << time_*time_step << endl;
	
	cout << "The neuron has fired " << cells_[0].Neuron::getSpikeNumb() << " times" <<endl;
	
}

bool Simulation::neurons_update()
{
	//updating all neurons in simulation
	for (size_t i(0); i< cells_.size(); ++i)
	{
		//when an external current is applied
		/*if(time_*time_step>abound and time_*time_step< bbound)
		{
			if((cells_[i].Neuron::update(time_step, time_*time_step, Iext))// convert back to time in double 
		 
				{//need to check the cell exists ! is within bounds
					cells_[i+1].recieve();
				} 
				
		}
		//when no external current is applied
		else {
			cells_[i].Neuron::update(time_step, time_*time_step);
		}*/

	}

	
	return true;
}
