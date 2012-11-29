#include "pch.h"
#include "SOMNetwork.h"
#include <cmath>

#include <cassert>

namespace NeuralNetwork {

	SOMNetwork::SOMNetwork(){

	}

	SOMNetwork::SOMNetwork(int layerSize[], int nRows, int nCols)
		:DistanceNetwork(layerSize), nRows(nRows), nCols(nCols)
	{
		assert(nRows*nCols==outputSize);
	}

	SOMNetwork::~SOMNetwork() {
		// TODO Auto-generated destructor stub
	}

	int SOMNetwork::NRows() const{
		return nRows;
	}
	int SOMNetwork::NCols() const{
		return nCols;
	}



	ostream &operator<<(ostream &os, const SOMNetwork& network){
		int nRows = network.nRows, nCols = network.nCols;
		vec output = network.output;
		for(int i=0; i<nRows; ++i){
			for(int j=0; j<nCols; ++j){
				os<<output[nCols*i+j]<<" ";
			}
			os<<endl;
		}
		os<<endl;
		return os;
	}


} /* namespace NeuralNetwork */
