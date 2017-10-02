#include "neuron.hpp"
#include <iostream>

using namespace std;

void set_sim_time();

double SIM_TIME;
double Iext;
double a;
double b;

int Neuron::cellCount=0;

int main()
{
	double time(0);
	double TIME_STEP(0.1); //decide if global or where it should go

	Neuron n1;
	set_sim_time();
	
	do{
		n1.update(Iext,TIME_STEP);
		time+=TIME_STEP;
	}
	while(time<= SIM_TIME);

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
