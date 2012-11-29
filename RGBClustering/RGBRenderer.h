#pragma once

#include "DirectXBase.h"
#include "armadillo-3.4.0\include\armadillo"
#include "SOM.h"
using namespace arma;


// This class renders simple text with a colored background.
ref class RGBRenderer sealed : public DirectXBase
{
public:
	RGBRenderer();
	// DirectXBase methods.
	virtual void CreateDeviceIndependentResources() override;
	virtual void CreateDeviceResources() override;
	virtual void CreateWindowSizeDependentResources() override;
	virtual void Render() override;

	// Method for updating time-dependent objects.
	void Update(float timeTotal, float timeDelta);
	void GetTrainingFactors(int *iterationCounter, double *learningRate, double *learningRadius, double *error);

	// Methods to save and load state in response to suspend.
	void SaveInternalState(Windows::Foundation::Collections::IPropertySet^ state);
	void LoadInternalState(Windows::Foundation::Collections::IPropertySet^ state);

	void Reset(){
		somRGB.Reset();
	}
	void SetInitialLearningRate(double x){
		somRGB.InitialLearningRate = x;
	}
	void SetInitialLearningRadius(double x){
		somRGB.InitialLearningRadius =x;
	}

private:
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> m_blackBrush, m_somBrush;
	Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormat;
	Microsoft::WRL::ComPtr<IDWriteTextLayout> m_textLayout;
	DWRITE_TEXT_METRICS m_textMetrics;
	Windows::Foundation::Point m_textPosition;
	bool m_renderNeeded;
	int m_backgroundColorIndex;
	SOM somRGB;
	void RGBDraw(const mat &board, int boardWidth, int boardHeight, int windowWidth, int windowHeight );
};