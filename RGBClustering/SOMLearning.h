#pragma once
/*
* SOMLearning.h
*
*  Created on: Jun 13, 2012
*      Author: letrungkien7
*/

#include <vector>
#include "armadillo-3.4.0\include\armadillo"

#include "UnsupervisedLearning.h"
#include "SOMNetwork.h"
using namespace std;
using namespace arma;

namespace NeuralNetwork {

	class SOMLearning :public UnsupervisedLearning {
	public:
		SOMLearning();
		SOMLearning(SOMNetwork *network, double learningRate, double learningRadius);
		virtual ~SOMLearning();

		virtual double Run(const vec &input);
		virtual double RunEpoch(vector<vec> input);
		virtual double Train(int times);

		void SetLearningRate(const double &learningRate);
		void SetLearningRadius(const double &learningRadius);

		double LearningRadius() const;
		double LearningRate() const;
		int NRows() const;
		int NCols() const;

		double Neighborhood(int i, int j);

	protected:
		double learningRate, learningRadius, squaredRadius;
		int nRows, nCols;
	};
} /* namespace NeuralNetwork */
