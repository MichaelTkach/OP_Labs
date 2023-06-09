#pragma once
#include "Matrix.h"
namespace laba7M {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ label2;
	private: int rows, cols;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->textBox1->Location = System::Drawing::Point(112, 111);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(137, 22);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(109, 69);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введіть розмірність";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(295, 111);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(196, 28);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Створити таблиці";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(113, 650);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(196, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Порівняти матриці";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				647)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(114, 171);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Size = System::Drawing::Size(377, 194);
			this->tableLayoutPanel1->TabIndex = 11;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				647)));
			this->tableLayoutPanel2->Location = System::Drawing::Point(114, 394);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->Size = System::Drawing::Size(377, 194);
			this->tableLayoutPanel2->TabIndex = 12;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(357, 646);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 24);
			this->label2->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(111, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 16);
			this->label3->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(111, 369);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 16);
			this->label4->TabIndex = 15;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkKhaki;
			this->ClientSize = System::Drawing::Size(867, 706);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"laba7_matrices";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		try {
			label2->Text = "";
			label3->Text = "";
			label4->Text = "";

			// Очищаем существующие поля
			tableLayoutPanel1->Controls->Clear();
			tableLayoutPanel1->ColumnStyles->Clear();
			tableLayoutPanel1->RowStyles->Clear();

			tableLayoutPanel2->Controls->Clear();
			tableLayoutPanel2->ColumnStyles->Clear();
			tableLayoutPanel2->RowStyles->Clear();

			// Получаем введенные пользователем числа
			String^ input = textBox1->Text;
			array<String^>^ dimensions = input->Split(' ');
			if (dimensions->Length != 2) {
				throw gcnew Exception("Invalid input. Please enter two integers separated by a space.");
			}


			if (!Int32::TryParse(dimensions[0], rows) || !Int32::TryParse(dimensions[1], cols)) {
				throw gcnew Exception("Invalid input. Please enter two integers separated by a space.");
			}

			if (rows <= 0 || cols <= 0) {
				throw gcnew Exception("Matrix dimensions must be positive.");
			}

			// Проверяем ограничение на размер матрицы не больше 6x6
			if (rows > 6 || cols > 6) {
				throw gcnew Exception("Matrix size cannot exceed 6x6.");
			}

			label3->Text = "Перша матриця";
			label4->Text = "Друга матриця";

			int cellSize = 50;
			tableLayoutPanel1->Size = System::Drawing::Size(cols * cellSize, rows * cellSize);

			// Создаем новые поля
			for (int row = 0; row < rows; row++) {
				for (int col = 0; col < cols; col++) {
					System::Windows::Forms::TextBox^ textbox = gcnew System::Windows::Forms::TextBox();
					textbox->Width = cellSize - 10;  // Уменьшаем ширину на 10 пикселей для вмещения в ячейку
					tableLayoutPanel1->Controls->Add(textbox, col, row);

					tableLayoutPanel1->Margin = System::Windows::Forms::Padding(5, 5 / 2, 5, 5 / 2);
					textbox->BackColor = System::Drawing::SystemColors::ScrollBar;

				}
			}

			tableLayoutPanel2->Size = System::Drawing::Size(cols * cellSize, rows * cellSize);
			// Создаем новые поля
			for (int row = 0; row < rows; row++) {
				for (int col = 0; col < cols; col++) {
					System::Windows::Forms::TextBox^ textbox = gcnew System::Windows::Forms::TextBox();
					textbox->Width = cellSize - 10;  // Уменьшаем ширину на 10 пикселей для вмещения в ячейку
					tableLayoutPanel2->Controls->Add(textbox, col, row);

					tableLayoutPanel2->Margin = System::Windows::Forms::Padding(5, 5 / 2, 5, 5 / 2);
					textbox->BackColor = System::Drawing::SystemColors::ScrollBar;


				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error");
		}
		catch (...) {
			MessageBox::Show("An error occurred.", "Error");
		}
	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int r, c;
			String^ input = textBox1->Text;
			array<String^>^ dimensions = input->Split(' ');
			if (!Int32::TryParse(dimensions[0], r) || !Int32::TryParse(dimensions[1], c) || (r != rows || c != cols)) {
				// Set the text of textBox1 to the values of rows and cols
				textBox1->Text = rows + " " + cols;
				throw gcnew Exception("Do not change the info about dimensions.");
			}

			Matrix^ matrix1 = gcnew Matrix(rows, cols, tableLayoutPanel1);
			Matrix^ matrix2 = gcnew Matrix(rows, cols, tableLayoutPanel2);
			double trace1 = matrix1->CalculateTrace();
			double trace2 = matrix2->CalculateTrace();

			if (trace1 > trace2) {
				label2->Text = "First matrix has larger trace: " + trace1.ToString();
			}
			else if (trace2 > trace1) {
				label2->Text = "Second matrix has larger trace: " + trace2.ToString();
			}
			else {
				label2->Text = "Both matrices have the same trace: " + trace1.ToString();
			}

		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error");
		}
		catch (...) {
			MessageBox::Show("An error occurred.", "Error");
		}

	}

	};
}
