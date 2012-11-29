#include "pch.h"
#include "SOMLearning.h"
#include "DistanceLayer.h"
#include <cmath>
#include <cassert>
namespace NeuralNetwork {
	SOMLearning::SOMLearning(){
	}
	SOMLearning::	SOMLearning(SOMNetwork *network, double learningRate, double learningRadius)
		:UnsupervisedLearning((SOMNetwork*)network), learningRate(learningRate),learningRadius(learningRadius),
		squaredRadius(2*learningRadius*learningRadius),
		nRows(network->nRows), nCols(network->nCols)
	{
	}
	SOMLearning::~SOMLearning(){

	}
	double SOMLearning::Run(const vec &input){
		double neighborhood = 0.0;
		double error = 0.0;

		network->Compute(input);
		int winner = ((SOMNetwork*)network)->GetWinner();

		DistanceLayer* layer =(DistanceLayer*)network->layers[0];
		mat *weight = &layer->weight;

		for(int i=0, neuronsNum=layer->size; i<neuronsNum; ++i){
			neighborhood = Neighborhood(i,winner);
			weight->col(i)+=learningRate*neighborhood*(input-weight->col(i));
			error+=norm(abs(input-weight->col(i)),1)*neighborhood;
		}
		return error;
	}

	double SOMLearning::RunEpoch(vector<vec> input){
		double error = 0.0;
		for(int i=0, num=input.size(); i<num; ++i ){
			error+=Run(input[i]);
		}
		return error;
	}
	double SOMLearning::Train(int times){
		double error =0;
		vec input(network->inputSize);
		for(int i=0; i<times; ++i){
			error = Run(input.randu());
		}
		return error;
	}

	void SOMLearning::SetLearningRate(const double &learningRate){
		this->learningRate= learningRate;
	}
	void SOMLearning::SetLearningRadius(const double &learningRadius){
		this->learningRadius = learningRadius;
		squaredRadius = 2*learningRadius*learningRadius;
	}

	double SOMLearning::Neighborhood(int i, int j){
		if(squaredRadius){
			return exp(-((i%nRows-j%nRows)*(i%nRows-j%nRows)+(i/nRows-j/nRows)*(i/nRows-j/nRows))/squaredRadius);
		}
		else{
			return 1;
		}

	}

	double SOMLearning::LearningRadius() const{
		return learningRadius;
	}
	double SOMLearning::LearningRate() const{
		return learningRate;
	}

} /* namespace NeuralNetwork */

