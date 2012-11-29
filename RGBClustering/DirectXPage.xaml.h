//
// BlankPage.xaml.h
// Declaration of the BlankPage.xaml class.
//

#pragma once

#include "DirectXPage.g.h"
#include "RGBRenderer.h"
#include "BasicTimer.h"


namespace RGBClustering
{
	using namespace Windows::UI::Xaml;
	/// <summary>
	/// A DirectX page that can be used on its own.  Note that it may not be used within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class DirectXPage sealed
	{
	public:
		DirectXPage();

		
		void SaveInternalState(Windows::Foundation::Collections::IPropertySet^ state);
		void LoadInternalState(Windows::Foundation::Collections::IPropertySet^ state);

	private:
		void OnPointerMoved(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ args);
		void OnPointerReleased(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ args);
		void OnWindowSizeChanged(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::WindowSizeChangedEventArgs^ args);
		void OnLogicalDpiChanged(Platform::Object^ sender);
		void OnOrientationChanged(Platform::Object^ sender);
		void OnDisplayContentsInvalidated(Platform::Object^ sender);
		void OnRendering(Object^ sender, Object^ args);
		void DispatcherTimer_Tick(Object^ sender, Object^ e);
		Windows::Foundation::EventRegistrationToken m_eventToken;

		RGBRenderer^ m_renderer;
		bool m_renderNeeded;

		Windows::Foundation::Point m_lastPoint;
		bool m_lastPointValid;

		BasicTimer^ m_timer;
		Windows::UI::Xaml::DispatcherTimer^ m_dispatcherTimer;
		int IterationCounter;
		double LearningRate, LearningRadius, Error;
		void StartButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void StopButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ResetButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void LearningRateTextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void InitialLearningRadiusTextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void InitialLearningRateTextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
	};
}
