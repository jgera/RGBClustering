#pragma once
#include "DistanceNetwork.h"

namespace NeuralNetwork {

	class SOMNetwork :public DistanceNetwork{
	public:
		SOMNetwork();
		SOMNetwork(int layerSize[], int nRows, int nCols);
		virtual ~SOMNetwork();

		friend ostream &operator<<(ostream &os, const SOMNetwork &network);
		friend class SOMLearning;

		int NRows() const;
		int NCols() const;

		void SetNRows(const int &n);
		void SetNCols(const int &n);

	protected:
		int nRows, nCols;
	};

	ostream &operator<<(ostream &os, const SOMNetwork &network);

} /* namespace NeuralNetwork */