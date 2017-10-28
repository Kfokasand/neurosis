#include "simulation.hpp"
#include <iostream>

using namespace std;

int main()
{	
	Simulation sim1(0.1);	
	
	sim1.Run();
	//rerun to check for memory leaks
	
	return 0;	
}



