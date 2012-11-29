#pragma once

#include "Network.h"

namespace NeuralNetwork {

	class DistanceNetwork :public Network{
	public:
		DistanceNetwork();
		DistanceNetwork(int layersSize[]);
		virtual ~DistanceNetwork();

		int GetWinner();
	};

} /* namespace NeuralNetwork */

