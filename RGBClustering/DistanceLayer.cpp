#include "pch.h"

#include "DistanceLayer.h"
#include <cassert>


namespace NeuralNetwork {

	DistanceLayer::DistanceLayer(int inputSize, int outputSize)
		:Layer(inputSize, outputSize)
	{

	}

	DistanceLayer::~DistanceLayer() {
		// TODO Auto-generated destructor stub
	}

	vec DistanceLayer::Compute(const vec &input){
		assert(input.size()==weight.n_rows);
		for(int i=0; i<size; ++i){
			output[i] = norm(weight.col(i)-input,2);
		}
		return output;
	}


} /* namespace NeuralNetwork */

