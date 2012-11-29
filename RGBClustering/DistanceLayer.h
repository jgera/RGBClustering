#pragma once
#include "Layer.h"

namespace NeuralNetwork {

	class DistanceLayer:public Layer {
	public:
		DistanceLayer(int inputSize, int outputSize);
		virtual ~DistanceLayer();

		virtual vec Compute(const vec & input);

		//friend class SOMLearning;
	};

} /* namespace NeuralNetwork */
