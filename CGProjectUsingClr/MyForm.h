#pragma once
#include<iostream>
#include<fstream>
#include <vector>
#include <string>
#include <sstream>
#include<list>

#include "../SPMathLibrary/SPMathPoint2D.h"
#include "../SPMathLibrary/SPMathLine2D.h"
#include "../SPMathReader/SPMathFileReader.h"
#include<iterator>
#include "../SPMathLibrary/SPMathHatch2D.h"
#include "../SPMathAlgorithm/SPMathHatchingAlgorithm.h"


namespace CGProjectUsingClr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Xml;
	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Graphics^ panel11;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ OpenFileToolStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ HatchPolygonToolStripMenuItem;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->OpenFileToolStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HatchPolygonToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Location = System::Drawing::Point(12, 29);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(504, 322);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->OpenFileToolStrip,
					this->HatchPolygonToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(569, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// OpenFileToolStrip
			// 
			this->OpenFileToolStrip->Name = L"OpenFileToolStrip";
			this->OpenFileToolStrip->Size = System::Drawing::Size(69, 20);
			this->OpenFileToolStrip->Text = L"Open File";
			this->OpenFileToolStrip->Click += gcnew System::EventHandler(this, &MyForm::OpenFileToolStrip_Click);
			// 
			// HatchPolygonToolStripMenuItem
			// 
			this->HatchPolygonToolStripMenuItem->Name = L"HatchPolygonToolStripMenuItem";
			this->HatchPolygonToolStripMenuItem->Size = System::Drawing::Size(100, 20);
			this->HatchPolygonToolStripMenuItem->Text = L"Hatch_Polygon";
			this->HatchPolygonToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::HatchPolygonToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 378);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		{
			Graphics^ g1 = panel1->CreateGraphics();
			SPMathPoint2D objp1(100,100);
			SPMathPoint2D objp2(200, 200);

			SPMathLine2D line(objp1, objp2);
			Graphics^ g = e->Graphics;

			
			Pen^ redPen = gcnew Pen(Color::Red);
			redPen->Width = 4;
			//g1->DrawLine(redPen, 10, 10, objp1.GetXCoordinate(), objp1.GetYCoordinate());
			
		}
	
	private:System::Void SPMathDrawLine(std::vector<SPMathLine2D> lineList)
	{
		Graphics^ g = panel1->CreateGraphics();
		
		float LineWidth = 4;
		Pen^ redPen = gcnew Pen(Color::Red, LineWidth);

		for (int i=0;i<lineList.size();i++)
		{
			g->DrawLine(redPen, int(lineList[i].GetStartPoint().GetXCoordinate()), int(lineList[i].GetStartPoint().GetYCoordinate()), int(lineList[i].GetEndPoint().GetXCoordinate()), int(lineList[i].GetEndPoint().GetYCoordinate()));
		}
	}

	private: System::Void OpenFileToolStrip_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::vector<SPMathLine2D> lineList;
		int linecnt = 0;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((openFileDialog1->OpenFile()) != nullptr)
			{
				String^ strfilename = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				String^ Readfile = File::ReadAllText(strfilename)->ToString();
				//String[]  lines = File::ReadAllLines(strfilename);

				std::string line;
				std::ifstream myfile("C:/Users/DELL/source/repos/CGProjectUsingClr/rectangle_data.txt");
				//std::vector<std::string> filecontent;
		
				if (myfile.is_open())
				{
					MessageBox::Show(Readfile);
					while (!myfile.eof())
					{
						
						std::getline(myfile, line);
						std::stringstream ss(line);
						linecnt = line.size();
						double pointarray[4] = {};           // array of points
						int cnt = 0;
						SPMathPoint2D startPoint;
						SPMathPoint2D endPoint;

						// Use while loop to check the getline() function condition.  
						while (std::getline(ss, line, ','))
						{
							pointarray[cnt] = stod(line);
							cnt++;
						}
						startPoint.SetXCoordinate(pointarray[0]);
						startPoint.SetYCoordinate(pointarray[1]);
						endPoint.SetXCoordinate(pointarray[2]);
						endPoint.SetYCoordinate(pointarray[3]);

						SPMathLine2D line(startPoint, endPoint);
						lineList.push_back(line);
						
					}
				}
				for (size_t i = 0; i < lineList.size(); i++)
				{
					SPMathDrawLine(lineList);
				}
			}
		}
		SPMathAlgorithm hatchingAlgorithm;
		vector<SPMathHatch2D> hatchList = hatchingAlgorithm.Algorithm(lineList);
		vector<SPMathLine2D> linelist;

		SPMathHatch2D newHatch;
		for(int i =0; i<hatchList.size();i++)
		{
			SPMathLine2D line(newHatch.GetHatch()[i].getHatchLine());
			linelist.push_back(line);

			for (int i = 0; i < linelist.size(); i++)
			{
				SPMathDrawLine(linelist);
			}
		}
	}
	
	
	private: System::Void HatchPolygonToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
				

	}
};
}
