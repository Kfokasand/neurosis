#include "neuron.hpp"
#include "gtest/gtest.h"



TEST (NeuronTest, MembranePotential_1Update) {
   
   Neuron neuron(1);
	double TimeStep (0.1);
	double Iext (1.0);
	neuron.setStim(true);
   
    //Test for a single update
    neuron.UpdateNeuron(TimeStep,Iext,2);
    EXPECT_EQ(20.0*(1.0-exp(-0.1/20.0)), neuron.getMembPot());
    
}

TEST (NeuronTest, MembranePotential_10000Update) 
{
	Neuron neuron(1);
	double TimeStep (0.1);
	double Iext (1.0);
	neuron.setStim(true);
	
	//Test for many updates : membrane potential should tend to 20 but there should be no spikes
    neuron.RepeatUpdate(10000,TimeStep,Iext);
    
    EXPECT_EQ(0, neuron.getSpikeNumb());
    
      EXPECT_GT(1E-4, fabs(19.9999 - neuron.getMembPot()));
    
}

TEST (NeuronTest, MembranePotential_10000Update_Empty) 
{
	Neuron neuron(1);
	double TimeStep (0.1);
	double Iext (1.0);
	neuron.setStim(true);
	    //Test when external imput stops: potential should tend to 0
    Iext=0;
    neuron.RepeatUpdate(1000,TimeStep,Iext);
    
    EXPECT_NEAR(0, neuron.getMembPot(), 1e-3);
	
}

//Excepted spike times for one isolated neuron under this current 92.4, 186.8, 281.2 and 375.6 (in ms)
TEST (Neurontest, FirstSpike)
{
	Neuron neuron(1);
	double TimeStep (0.1);
	double Iext (1.01);
	neuron.setStim(true);

	//Test if first spike occurs at expected time
	neuron.RepeatUpdate(923,TimeStep,Iext);

	EXPECT_EQ(0, neuron.getSpikeNumb());

	neuron.UpdateNeuron(TimeStep,Iext,2);

	EXPECT_EQ(1, neuron.getSpikeNumb());

	EXPECT_EQ(0.0, neuron.getMembPot());
}


TEST (Neurontest, EnoughSpikes)
{
	Neuron neuron(1);
	double TimeStep (0.1);
	double Iext (1.01);
	neuron.setStim(true);
	
	//testing if enough spikes occur
	neuron.RepeatUpdate(4000,TimeStep,Iext);
	
	EXPECT_EQ(4, neuron.getSpikeNumb());
}

TEST (Networktest, ExcitationDelay)
{
	Neuron neuron1(1);
	Neuron neuron2(1);
	double TimeStep (0.1);
	double Iext (1.01);
	neuron1.setStim(true);
	neuron2.setStim(true);

	int delay=15;
	
	for (int i(0); i<923+delay; ++i)
	{
		if(neuron1.UpdateNeuron(TimeStep,Iext,2))
		{
			cout << i <<endl;
			neuron2.Receive(0.1,0);
			EXPECT_EQ(0.0, neuron1.getMembPot());
			EXPECT_EQ(0.0, neuron2.getMembPot());
		}
	}
	neuron2.RepeatUpdate(delay+1, TimeStep,0);
	EXPECT_EQ(0.1, neuron2.getMembPot());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
