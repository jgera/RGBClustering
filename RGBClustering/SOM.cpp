#include "pch.h"
#include "SOM.h"


SOM::SOM(void):
	InitialLearningRate(0.4), InitialLearningRadius(25), 
	Lambda(0.005), Error(1000.0), ErrorThreshold(0.01), BoardWidth(100), BoardHeight(100),
	IterationCounter(0), IterationMax(50000)
{
	int layersSize[2] = {3, BoardWidth*BoardHeight};
	Network = new SOMNetwork(layersSize, BoardWidth, BoardHeight);
	Teacher = new SOMLearning(Network, InitialLearningRate, InitialLearningRadius);
}


SOM::~SOM(void)
{
	delete Network;
	delete Teacher;
}

const mat& SOM::Board(){
	return Network->layers[0]->Weight();
}

void SOM::Train(int trainingTimes){
	int cnt = 0;
	while(cnt++<trainingTimes){
		static vec randInput(3);
		if(Error < ErrorThreshold || IterationCounter > IterationMax){
			return ;
		}
		IterationCounter++;
		Error = Teacher->Run(randInput.randu());
		if(Teacher->LearningRate()>0.001)
			Teacher->SetLearningRate(InitialLearningRate*exp(-IterationCounter*Lambda));
		if(Teacher->LearningRadius()>0.1)
			Teacher->SetLearningRadius(InitialLearningRadius*exp(-IterationCounter*Lambda));
	}
}
