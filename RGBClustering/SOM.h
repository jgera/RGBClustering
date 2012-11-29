#pragma once

#include "SOMNetwork.h"
#include "SOMLearning.h"

#include "armadillo-3.4.0\include\armadillo"

using namespace arma;
using namespace NeuralNetwork;


class SOM
{
public:
	SOM(void);
	~SOM(void);

	SOMNetwork *Network;
	SOMLearning *Teacher;

	void Train(int trainingTimes = 1);
	void Reset(){
		Network->Randomize();
		Teacher->SetLearningRate(InitialLearningRate);
		Teacher->SetLearningRadius(InitialLearningRadius);
		IterationCounter = 0;
		Error = 1000;
	}

	const mat &Board();
	double InitialLearningRate;
	double InitialLearningRadius;
	double Lambda;
	double Error;
	double ErrorThreshold;
	int IterationMax;
	int IterationCounter;
	int BoardWidth;
	int BoardHeight;
};

