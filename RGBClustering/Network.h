#pragma once
/*
* Network.h
*
*  Created on: Jun 12, 2012
*      Author: letrungkien7
*/

#ifndef NETWORK_H_
#define NETWORK_H_

#include <vector>
#include "armadillo-3.4.0\include\armadillo"
#include "ActivationFunction.h"
#include "Layer.h"

using namespace std;
using namespace arma;
namespace NeuralNetwork {

	class Network {
	public:
		Network();
		Network(int layersSize[], int layersNum);
		virtual ~Network();

		virtual vec Compute(const vec &input);
		void Randomize();

		vec Output() const;
		int InputSize() const;
		int OutputSize() const;
		int LayersNum() const;
		void SetLayersSize(int layersSize[], int layersNum);

		vector<Layer*> layers;

		friend class BackPropagationLearning;
		friend class ElasticNetworkLearning;
		friend class SOMLearning;
	protected:
		vec output;
		int inputSize,outputSize,layersNum;
	};

} /* namespace NeuralNetwork */
#endif /* NETWORK_H_ */
