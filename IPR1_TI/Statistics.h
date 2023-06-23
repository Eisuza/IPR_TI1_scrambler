#pragma once

namespace IPR1TI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Statistics : public System::Windows::Forms::Form
	{
	public:
		Statistics(void)
		{
			InitializeComponent();
		}

	protected:
		~Statistics()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ original_frequency_chart;
	protected:
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ encrypted_frequency_chart;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Statistics::typeid));
			this->original_frequency_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->encrypted_frequency_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->original_frequency_chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->encrypted_frequency_chart))->BeginInit();
			this->SuspendLayout();
			// 
			// original_frequency_chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->original_frequency_chart->ChartAreas->Add(chartArea1);
			legend1->Alignment = System::Drawing::StringAlignment::Center;
			legend1->BackColor = System::Drawing::Color::Transparent;
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend1->ForeColor = System::Drawing::Color::DimGray;
			legend1->Name = L"Legend1";
			legend1->Title = L"Гистограмма для исходного текста";
			legend1->TitleForeColor = System::Drawing::Color::Maroon;
			legend1->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::ThickGradientLine;
			legend1->TitleSeparatorColor = System::Drawing::Color::LightSalmon;
			this->original_frequency_chart->Legends->Add(legend1);
			this->original_frequency_chart->Location = System::Drawing::Point(20, 20);
			this->original_frequency_chart->Name = L"original_frequency_chart";
			series1->ChartArea = L"ChartArea1";
			series1->Color = System::Drawing::Color::IndianRed;
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->LegendText = L"количество повторений";
			series1->Name = L"Series1";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			this->original_frequency_chart->Series->Add(series1);
			this->original_frequency_chart->Size = System::Drawing::Size(1160, 660);
			this->original_frequency_chart->TabIndex = 0;
			this->original_frequency_chart->Text = L"chart1";
			this->original_frequency_chart->Visible = false;
			// 
			// encrypted_frequency_chart
			// 
			chartArea2->Name = L"ChartArea1";
			this->encrypted_frequency_chart->ChartAreas->Add(chartArea2);
			legend2->Alignment = System::Drawing::StringAlignment::Center;
			legend2->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend2->ForeColor = System::Drawing::Color::DimGray;
			legend2->Name = L"Legend1";
			legend2->Title = L"Гистограмма для зашифрованного текста";
			legend2->TitleForeColor = System::Drawing::Color::Maroon;
			legend2->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::ThickGradientLine;
			legend2->TitleSeparatorColor = System::Drawing::Color::DarkSalmon;
			this->encrypted_frequency_chart->Legends->Add(legend2);
			this->encrypted_frequency_chart->Location = System::Drawing::Point(20, 20);
			this->encrypted_frequency_chart->Name = L"encrypted_frequency_chart";
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::LightSalmon;
			series2->Legend = L"Legend1";
			series2->LegendText = L"количество повторений";
			series2->Name = L"Series1";
			this->encrypted_frequency_chart->Series->Add(series2);
			this->encrypted_frequency_chart->Size = System::Drawing::Size(1160, 660);
			this->encrypted_frequency_chart->TabIndex = 1;
			this->encrypted_frequency_chart->Text = L"chart2";
			this->encrypted_frequency_chart->Visible = false;
			// 
			// Statistics
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->encrypted_frequency_chart);
			this->Controls->Add(this->original_frequency_chart);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1200, 700);
			this->MinimumSize = System::Drawing::Size(1200, 700);
			this->Name = L"Statistics";
			this->Text = L"Statistics";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->original_frequency_chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->encrypted_frequency_chart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		public:
			void set_input_frequency(String^ x, int y) {
				this->original_frequency_chart->Series[0]->Points->AddXY(x, y);
			}
		public:
			void clear_input_diagram() {
				this->original_frequency_chart->Series[0]->Points->Clear();
			}
		public:
			void set_encryption_frequency(int x, int y) {
				this->encrypted_frequency_chart->Series[0]->Points->AddXY(x, y);
			}
		public:
			void clear_encryption_diagram() {
				this->encrypted_frequency_chart->Series[0]->Points->Clear();
			}
		public:
			void set_input_diagram_visible() {
				this->original_frequency_chart->Visible = true;
			}
		public:
			void set_encryption_diagram_visible() {
				this->encrypted_frequency_chart->Visible = true;
			}
	};

}