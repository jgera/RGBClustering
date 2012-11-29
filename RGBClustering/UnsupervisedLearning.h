#pragma once
#include <vector>
#include "armadillo-3.4.0\include\armadillo"
#include "Network.h"

using namespace std;
using namespace arma;

namespace NeuralNetwork {
	class UnsupervisedLearning {
	public:
		UnsupervisedLearning();
		UnsupervisedLearning(Network * network);
		virtual ~UnsupervisedLearning();

		virtual double Run(const vec &input)=0;
		virtual double RunEpoch(vector<vec> input)=0;
		virtual double Train(int times)=0;

		Network *network;
	};

} /* namespace NeuralNetwork */