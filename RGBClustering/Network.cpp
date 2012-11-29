#include "pch.h"
#include "Network.h"

/*
* Network.cpp
*
*  Created on: Jun 12, 2012
*      Author: letrungkien7
*/

#include <algorithm>
#include <cassert>

namespace NeuralNetwork {

	Network::Network(){
	}
	Network::Network(int layersSize[], int layersNum)
		try:inputSize(layersSize[0]),outputSize(layersSize[layersNum-1]),layersNum(layersNum-1)
	{
		output.set_size(outputSize);
		layers.resize(layersNum-1);
	}
	catch(exception &e){
		cerr<<"Exception at Network Class Constructors:"<<e.what();
	}
	Network::~Network(){
		layers.clear();
	}

	vec Network::Compute(const vec &input){
		assert((int)input.size()==inputSize);
		output = input;
		for(int i=0; i<layersNum; ++i){
			output = layers[i]->Compute(output);
		}
		return output;
	}

	vec Network::Output() const{
		return output;
	}
	int Network::InputSize() const{
		return inputSize;
	}
	int Network::OutputSize() const{
		return outputSize;
	}
	int Network::LayersNum() const{
		return layersNum;
	}

	void Network::SetLayersSize(int layersSize[], int layersNum){
		inputSize = layersSize[0];
		outputSize = layersSize[layersNum-1];
		output.set_size(outputSize);
		layers.resize(layersNum-1);
	}

	void Network::Randomize(){
		for(int i=0; i<layersNum; ++i)
			layers[i]->Randomize();
	}
} /* namespace NeuralNetwork */
