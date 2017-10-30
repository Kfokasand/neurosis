#include "neuron.hpp"
#include "network.hpp"
#include "simulation.hpp"
#include "gtest/gtest.h"

TEST (NeuronTest, MembPot_1step_positivInput) {
    Neuron neuron(1);
    //First update test
    
    neuron.UpdateNeuron(0.1,1.0,1);
    EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0)), neuron.getMembPot());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
