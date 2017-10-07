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

int Neuron::cellCount=3;

int main()
{
	double time(0);
	double TIME_STEP(0.1); //decide if global or where it should go

	Neuron n1;
  
	ofstream history;
	history.open("history.txt");
	set_sim_time();
	set_current();
	
	cout << "settings are : " << Iext << " " << TIME_STEP << endl;
	
	do{

		if(time >a and time< b)
		{
			n1.Neuron::update(TIME_STEP, time, Iext);
		} else {
			n1.Neuron::update(TIME_STEP, time);
		}
		time+=TIME_STEP;
		//check if external current applied or not to call update
		history << n1.getMembPot() << " " ;
		
	}
	while(time<= SIM_TIME);

	cout << time << endl;
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
