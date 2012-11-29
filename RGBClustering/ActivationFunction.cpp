#include "pch.h"
#include "ActivationFunction.h"

/*
* ActivationFunction.cpp
*
*  Created on: Jun 11, 2012
*      Author: letrungkien7
*/
#include "armadillo-3.4.0\include\armadillo"
#include <cmath>

using namespace std;

namespace NeuralNetwork {

	ActivationFunction::ActivationFunction() {
		// TODO Auto-generated constructor stub
	}

	ActivationFunction::~ActivationFunction() {
		// TODO Auto-generated destructor stub
	}

	double ActivationFunction::Function(double x, AFType type){
		switch(type){
		case SIGMOID:
			return sigmoid(x);
		case LINEAR:
			return linear(x);
		case NONE:
		default:
			return 0.0;
		}
	}

	double ActivationFunction::Derivative(double x, AFType type){
		switch(type){
		case SIGMOID:
			return sigmoid_derivative(x);
		case LINEAR:
			return linear_derivative(x);
		case NONE:
		default:
			return 0.0;
		}
	}

	vec ActivationFunction::FunctionVector(const vec &x, AFType type){
		int size = x.size();
		vec y(size);
		for(int i=0; i<size; ++i)
			y[i]=Function(x[i],type);
		return y;
	}
	vec ActivationFunction::DerivativeVector(const vec &x, AFType type){
		int size = x.size();
		vec y(size);
		for(int i=0; i<size; ++i)
			y[i]=Derivative(x[i],type);
		return y;
	}

	double ActivationFunction::sigmoid(double x){
		return 1.0 / (1.0 + exp(-x));
	}

	double ActivationFunction:: sigmoid_derivative(double x)
	{
		return sigmoid(x) * (1 - sigmoid(x));
	}

	double ActivationFunction:: linear(double x)
	{
		return x;
	}

	double ActivationFunction:: linear_derivative(double x)
	{
		return 1;
	}

	double ActivationFunction:: gaussian(double x)
	{
		return exp(-pow(x, 2));
	}

	double ActivationFunction:: gaussian_derivative(double x)
	{
		return -2.0*x*gaussian(x);
	}

	double ActivationFunction::rationalSigmoid(double x)
	{
		return x/(1.0+sqrt(1.0+x*x));
	}
	double ActivationFunction:: rationalSigmoid_derivative(double x)
	{
		double val = sqrt(1.0+x*x);
		return 1.0 / (val * (1 + val));
	}

} /* namespace NeuralNetwork */
