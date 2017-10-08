#include "neuron.hpp"
#include <iostream>

#include <fstream>


using namespace std;

void set_sim_time();
void set_current();

double SIM_TIME;
double Iext;
double a;
double b;

int Neuron::cellCount=0;

int main()
{
	double time(0);
	double TIME_STEP(0.1); //decide if global or where it should go

	//creating neuron for simulation
	Neuron n1;
  
	//opening channel to store membrane potentials
	ofstream history;
	history.open("history.txt");
	
	//setting simulation values
	//time
	set_sim_time();
	//external current applied
	set_current();
	
	cout << "settings are : " << Iext << " " << TIME_STEP << endl;
	
	//updating cell
	do{
		//when an external current is applied
		if(time >a and time< b)
		{
			n1.Neuron::update(TIME_STEP, time, Iext);
		} 
		//when no external current is applied
		else {
			n1.Neuron::update(TIME_STEP, time);
		}
		
		//storing membrane potential value in.txt file
		history << n1.getMembPot() << " " ;	
		
		//incremeting simulation time
		time+=TIME_STEP;
	}
	while(time<= SIM_TIME);

	cout << time << endl;
	cout << "The neuron fired " << n1.getSpikeNumb() << " times. "<<endl;
	return 0;	
}

void set_sim_time()
{
 //check the imput
	cout << "Set simulation time in ms : ";
	cin>> SIM_TIME;
	
}

void set_current()
{
	//check the imput
	cout<< "Set value of external current :";
	cin>>Iext;
	cout << "Set time limits : a=";
	cin>>a;
	cout << "b=";
	cin>>b;
}
