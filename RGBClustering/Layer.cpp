#include "pch.h"
#include "Layer.h"

/*
* Layer.cpp
*
*  Created on: Jun 12, 2012
*      Author: letrungkien7
*/
#include <cassert>
#include <algorithm>


namespace NeuralNetwork {

	Layer::Layer(int inputSize, int outputSize)
		:size(outputSize)
	{
		input.zeros(size);
		output.zeros(size);
		weight.randn(inputSize, outputSize);
	}

	Layer::~Layer() {
	}

	void Layer::Randomize(const int range){
		weight.randn();
		for(int i=0, n=weight.size(); i<n; ++i)
			if(weight[i]>range) weight[i]=range;
	}

	vec Layer::Input() const{
		return input;
	}
	vec Layer::Ouput() const{
		return output;
	}
	mat Layer::Weight() const{
		return weight;
	}
	int Layer::Size() const{
		return size;
	}

	void Layer::SetInput(const vec &input){
		this->input = input;
	}
	void Layer::SetOuput(const vec &output){
		this->output = output;
	}
	void Layer::SetWeight(const mat &weight){
		this->weight = weight;
	}
	void Layer::SetSize(const int &size){
		this->size = size;
	}


} /* namespace NeuralNetwork */
