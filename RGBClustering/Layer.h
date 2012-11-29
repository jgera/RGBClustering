#pragma once

#include "armadillo-3.4.0\include\armadillo"
#include "ActivationFunction.h"

using namespace arma;

namespace NeuralNetwork {

	class Layer {
	public:
		Layer(int inputSize, int outputSize);
		virtual ~Layer();

		virtual vec Compute(const vec & input)=0;
		virtual void Randomize(const int range=1);

		vec Input() const;
		vec Ouput() const;
		mat Weight() const;
		int Size() const;

		void SetInput(const vec &);
		void SetOuput(const vec &);
		void SetWeight(const mat &);
		void SetSize(const int &);

		friend class BackPropagationLearning;
		friend class ElasticNetworkLearning;
		friend class SOMLearning;

	protected:
		vec input, output;
		mat weight;
		int size;
	};
} /* namespace NeuralNetwork */