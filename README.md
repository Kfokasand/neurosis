# neurosis
BA3 SV informatics project

This programm allows to simulate the neural activity of a network made of 12500 neurons. It records membrane potential for each neuron at a given step of time and delivers them in a txt file (ble.txt)

Simulations can be ran Custom (selecting parameters) or Automatic


------------
Automatic: Simulation runs with 

12 000 neurons
1000 excitatory with a weight of 0.1
250 inhibitory with a weight of -0.5

Each neuron has 1000 excitatory and 250 inhibitory incoming connections.
Simulation time : 1000 ms (10 000 steps)
Time of one Step: 0.1 ms

The user can choose the recording boundaries in ms.

------------

Custom: The user can select the parameters

weight (Je) of excitatory inputs
weight (Ji) of inhibitory inputs

background noise (external random excitation): vext/vthr

Time of simulation

Recording boudaries

The rest of the parameters are the same as for Automatic Simulation


------------
General:
Simulations steps are alway 0.1 ms long

NB: programmed external stimulation (Iext) is switched off by default, methods using it have only been kept for testing purposes


------------
Neuron parameters are :
(these cannot be changed by user)

Capacity : 1.0
Membrane Resistance : 20.0 GOhm
Membrane time constant: 20.0 ms
Refractory period: 2.0 ms
Membrane resetting value: 0 mV
Membrane spike threshold: 20 mV
Synaptic delay: 1.5 ms


