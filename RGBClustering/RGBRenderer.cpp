#include "pch.h"
#include "RGBRenderer.h"

using namespace D2D1;
using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Core;

RGBRenderer::RGBRenderer() :
	m_renderNeeded(true)
{
}

void RGBRenderer::CreateDeviceIndependentResources()
{
	DirectXBase::CreateDeviceIndependentResources();

	DX::ThrowIfFailed(
		m_dwriteFactory->CreateTextFormat(
			L"Segoe UI",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			42.0f,
			L"en-US",
			&m_textFormat
			)
		);

	DX::ThrowIfFailed(
		m_textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING)
		);
}

void RGBRenderer::CreateDeviceResources()
{
	DirectXBase::CreateDeviceResources();

	DX::ThrowIfFailed(
		m_d2dContext->CreateSolidColorBrush(
			ColorF(ColorF::Black),
			&m_blackBrush
			)
		);
	DX::ThrowIfFailed(
		m_d2dContext->CreateSolidColorBrush(
			ColorF(ColorF::Black),
			&m_somBrush
			)
		);
	Platform::String^ text = "";

	DX::ThrowIfFailed(
		m_dwriteFactory->CreateTextLayout(
			text->Data(),
			text->Length(),
			m_textFormat.Get(),
			700, // maxWidth.
			1000, // maxHeight.
			&m_textLayout
			)
		);

	DX::ThrowIfFailed(
		m_textLayout->GetMetrics(&m_textMetrics)
		);
}

void RGBRenderer::CreateWindowSizeDependentResources()
{
	DirectXBase::CreateWindowSizeDependentResources();

	// Add code to create window size dependent objects here.
}

void RGBRenderer::Update(float timeTotal, float timeDelta)
{
	(void) timeTotal; // Unused parameter.
	(void) timeDelta; // Unused parameter.

	// Add code to update time dependent objects here.
	somRGB.Train(1);
}

void RGBRenderer::Render()
{
	m_d2dContext->BeginDraw();

	m_d2dContext->Clear(ColorF(D2D1::ColorF::BlueViolet));

	// Position the rendered text.
	Matrix3x2F translation = Matrix3x2F::Translation(
		m_windowBounds.Width / 4.0f, //- m_textMetrics.widthIncludingTrailingWhitespace / 2.0f,
		m_windowBounds.Height / 8.0f// - m_textMetrics.height / 2.0f
		);

	// Note that the m_orientationTransform2D matrix is post-multiplied here
	// in order to correctly orient the text to match the display orientation.
	// This post-multiplication step is required for any draw calls that are
	// made to the swap chain's target bitmap. For draw calls to other targets,
	// this transform should not be applied.
	
	m_d2dContext->SetTransform(translation * m_orientationTransform2D);

	m_d2dContext->DrawTextLayout(
		Point2F(0.0f, 0.0f),
		m_textLayout.Get(),
		m_blackBrush.Get(),
		D2D1_DRAW_TEXT_OPTIONS_NO_SNAP
		);

	RGBDraw(somRGB.Network->layers[0]->Weight(), somRGB.BoardWidth, somRGB.BoardHeight,
	m_windowBounds.Width/2, 3*m_windowBounds.Height/4 );

	// Ignore D2DERR_RECREATE_TARGET. This error indicates that the device
	// is lost. It will be handled during the next call to Present.
	HRESULT hr = m_d2dContext->EndDraw();
	if (hr != D2DERR_RECREATE_TARGET)
	{
		DX::ThrowIfFailed(hr);
	}

	m_renderNeeded = false;
}


void RGBRenderer::SaveInternalState(IPropertySet^ state)
{
	if (state->HasKey("m_backgroundColorIndex"))
	{
		state->Remove("m_backgroundColorIndex");
	}
	if (state->HasKey("m_textPosition"))
	{
		state->Remove("m_textPosition");
	}
	state->Insert("m_backgroundColorIndex", PropertyValue::CreateInt32(m_backgroundColorIndex));
	state->Insert("m_textPosition", PropertyValue::CreatePoint(m_textPosition));
}

void RGBRenderer::LoadInternalState(IPropertySet^ state)
{
	if (state->HasKey("m_backgroundColorIndex") && state->HasKey("m_textPosition"))
	{
		m_backgroundColorIndex = safe_cast<IPropertyValue^>(state->Lookup("m_backgroundColorIndex"))->GetInt32();
		m_textPosition = safe_cast<IPropertyValue^>(state->Lookup("m_textPosition"))->GetPoint();
	}
}

void RGBRenderer::RGBDraw(const mat &board, int boardWidth, int boardHeight, int windowWidth, int windowHeight ){
	assert(boardWidth*boardHeight==(int)board.n_cols);
	double gridWidth = windowWidth/(double)boardWidth;
	double gridHeight = windowHeight/(double)boardHeight;

	D2D1_RECT_F rect;

	for(int i=0; i<boardHeight; ++i){
		for(int j=0; j<boardWidth; ++j){
			m_somBrush->SetColor(ColorF(board.at(0,boardWidth*i+j),board.at(1,boardWidth*i+j),board.at(2,boardWidth*i+j)));
			m_d2dContext->FillRectangle(RectF( j*gridWidth, (i+1)*gridHeight, (j+1)*gridWidth, i*gridHeight), m_somBrush.Get());
		}
	}
}

void RGBRenderer::GetTrainingFactors(int *iterationCounter, double *learningRate, double *learningRadius, double *error){
	*iterationCounter = somRGB.IterationCounter;
	*learningRate = somRGB.Teacher->LearningRate();
	*learningRadius = somRGB.Teacher->LearningRadius();
	*error = somRGB.Error;
}