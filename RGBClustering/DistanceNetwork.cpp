#include "pch.h"
/*
* DistanceNetwork.cpp
*
*  Created on: Jun 12, 2012
*      Author: letrungkien7
*/

#include "DistanceNetwork.h"
#include "DistanceLayer.h"


namespace NeuralNetwork {

	DistanceNetwork::DistanceNetwork(){}

	DistanceNetwork::DistanceNetwork(int layersSize[])
		:Network(layersSize, 2)
	{
		layers[0]=(DistanceLayer*)(new DistanceLayer(layersSize[0], layersSize[1]));
	}

	DistanceNetwork::~DistanceNetwork() {

	}

	int DistanceNetwork::GetWinner(){
		double	min = output[0];
		int		minIndex = 0;

		for (int i=0 ; i < outputSize; i++ )
		{
			if ( output[i] < min )
			{
				// found new MIN value
				min = output[i];
				minIndex = i;
			}
		}

		return minIndex;
	}

} /* namespace NeuralNetwork */
