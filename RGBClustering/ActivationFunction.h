#pragma once
#include "armadillo-3.4.0\include\armadillo"

using namespace arma;

namespace NeuralNetwork {

	enum AFType{NONE, SIGMOID, LINEAR};

	class ActivationFunction {
	public:
		ActivationFunction();
		virtual ~ActivationFunction();

		static double Function(double x, AFType type);
		static double Derivative(double x, AFType type);
		static vec FunctionVector(const vec &x, AFType type);
		static vec DerivativeVector(const vec &x, AFType type);


	private:
		static double sigmoid(double x);
		static double sigmoid_derivative(double x);
		static double linear(double x);
		static double linear_derivative(double x);
		static double gaussian(double x);
		static double gaussian_derivative(double x);
		static double rationalSigmoid(double x);
		static double rationalSigmoid_derivative(double x);
	};

} /* namespace NeuralNetwork */



