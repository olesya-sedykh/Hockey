#pragma once
#include "Hockey.h"

namespace Hockey {

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  add_goalkeeper_left;

	protected:

	protected:



	private: System::Windows::Forms::Button^  add_defender_left;



	private: System::Windows::Forms::Button^  add_offensive_left;
	private: System::Windows::Forms::Button^  add_goalkeeper_right;
	private: System::Windows::Forms::Button^  add_depender_right;
	private: System::Windows::Forms::Button^  add_offensive_right;


	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		//метод перерисовки поля
		void redraw_field() {
			//создаётся объект класса Bitmap с изображением пустого поля
			Bitmap^ image = gcnew Bitmap("field.png");
			//вызывается метод рисования игроков
			playingField.draw_field(image);
			//полю Image объекта класса pictureBox присваивается изменённое изображение
			pictureBox1->Image = image;
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->add_goalkeeper_left = (gcnew System::Windows::Forms::Button());
			this->add_defender_left = (gcnew System::Windows::Forms::Button());
			this->add_offensive_left = (gcnew System::Windows::Forms::Button());
			this->add_goalkeeper_right = (gcnew System::Windows::Forms::Button());
			this->add_depender_right = (gcnew System::Windows::Forms::Button());
			this->add_offensive_right = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			//this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Image = gcnew Bitmap("field.png");
			this->pictureBox1->Location = System::Drawing::Point(36, 148);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1200, 622);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// add_goalkeeper_left
			// 
			this->add_goalkeeper_left->Location = System::Drawing::Point(36, 21);
			this->add_goalkeeper_left->Name = L"add_goalkeeper_left";
			this->add_goalkeeper_left->Size = System::Drawing::Size(120, 105);
			this->add_goalkeeper_left->TabIndex = 1;
			this->add_goalkeeper_left->Text = L"Добавить вратаря";
			this->add_goalkeeper_left->UseVisualStyleBackColor = true;
			this->add_goalkeeper_left->Click += gcnew System::EventHandler(this, &MyForm::add_goalkeeper_left_Click);
			// 
			// add_defender_left
			// 
			this->add_defender_left->Location = System::Drawing::Point(177, 21);
			this->add_defender_left->Name = L"add_defender_left";
			this->add_defender_left->Size = System::Drawing::Size(120, 105);
			this->add_defender_left->TabIndex = 5;
			this->add_defender_left->Text = L"Добавить защитника";
			this->add_defender_left->UseVisualStyleBackColor = true;
			this->add_defender_left->Click += gcnew System::EventHandler(this, &MyForm::add_defender_left_Click);
			// 
			// add_offensive_left
			// 
			this->add_offensive_left->Location = System::Drawing::Point(318, 21);
			this->add_offensive_left->Name = L"add_offensive_left";
			this->add_offensive_left->Size = System::Drawing::Size(137, 105);
			this->add_offensive_left->TabIndex = 6;
			this->add_offensive_left->Text = L"Добавить нападающего";
			this->add_offensive_left->UseVisualStyleBackColor = true;
			this->add_offensive_left->Click += gcnew System::EventHandler(this, &MyForm::add_offensive_left_Click);
			// 
			// add_goalkeeper_right
			// 
			this->add_goalkeeper_right->Location = System::Drawing::Point(814, 21);
			this->add_goalkeeper_right->Name = L"add_goalkeeper_right";
			this->add_goalkeeper_right->Size = System::Drawing::Size(120, 105);
			this->add_goalkeeper_right->TabIndex = 7;
			this->add_goalkeeper_right->Text = L"Добавить вратаря";
			this->add_goalkeeper_right->UseVisualStyleBackColor = true;
			this->add_goalkeeper_right->Click += gcnew System::EventHandler(this, &MyForm::add_goalkeeper_right_Click);
			// 
			// add_depender_right
			// 
			this->add_depender_right->Location = System::Drawing::Point(958, 21);
			this->add_depender_right->Name = L"add_depender_right";
			this->add_depender_right->Size = System::Drawing::Size(120, 105);
			this->add_depender_right->TabIndex = 8;
			this->add_depender_right->Text = L"Добавить защитника";
			this->add_depender_right->UseVisualStyleBackColor = true;
			this->add_depender_right->Click += gcnew System::EventHandler(this, &MyForm::add_defender_right_Click);
			// 
			// add_offensive_right
			// 
			this->add_offensive_right->Location = System::Drawing::Point(1099, 21);
			this->add_offensive_right->Name = L"add_offensive_right";
			this->add_offensive_right->Size = System::Drawing::Size(137, 105);
			this->add_offensive_right->TabIndex = 9;
			this->add_offensive_right->Text = L"Добавить нападающего";
			this->add_offensive_right->UseVisualStyleBackColor = true;
			this->add_offensive_right->Click += gcnew System::EventHandler(this, &MyForm::add_offensive_right_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1270, 791);
			this->Controls->Add(this->add_offensive_right);
			this->Controls->Add(this->add_depender_right);
			this->Controls->Add(this->add_goalkeeper_right);
			this->Controls->Add(this->add_offensive_left);
			this->Controls->Add(this->add_defender_left);
			this->Controls->Add(this->add_goalkeeper_left);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"Window";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//обработчик события нажатия на кнопку добавления синего вратаря
		private: System::Void add_goalkeeper_left_Click(System::Object^  sender, System::EventArgs^  e) {
			//проверяем, возможно ли добавить вратаря в данную команду
			//если да, он добавляется; иначе выводится сообщение об ошибке
			if (!playingField.add("goalkeeper", false, pictureBox1->Image->Size.Width / 2, pictureBox1->Image->Size.Height / 2)) {
				MessageBox::Show("Нельзя добавить более одного вратаря для одной команды");
			}

			//вызывается функция перерисовки игрового поля
			redraw_field();
		}
		
		//обработчик события нажатия на кнопку добавления синего защитника
		private: System::Void add_defender_left_Click(System::Object^  sender, System::EventArgs^  e) {
			//проверяем, возможно ли добавить защитника в данную команду
			//если да, он добавляется; иначе выводится сообщение об ошибке
			if (!playingField.add("defender", false, pictureBox1->Image->Size.Width / 2, pictureBox1->Image->Size.Height / 2)) {
				MessageBox::Show("Нельзя добавить более двух защитников для одной команды");
			}

			//вызывается функция перерисовки игрового поля
			redraw_field();
		}
		
		//обработчик события нажатия на кнопку добавления синего нападающего
		private: System::Void add_offensive_left_Click(System::Object^  sender, System::EventArgs^  e) {
			//проверяем, возможно ли добавить нападающего в данную команду
			//если да, он добавляется; иначе выводится сообщение об ошибке
			if (!playingField.add("offensive", false, pictureBox1->Image->Size.Width / 2, pictureBox1->Image->Size.Height / 2)) {
				MessageBox::Show("Нельзя добавить более трёх нападающих для одной команды");
			}

			//вызывается функция перерисовки игрового поля
			redraw_field();
		}
		
		//обработчик события нажатия на кнопку добавления красного вратаря
		private: System::Void add_goalkeeper_right_Click(System::Object^  sender, System::EventArgs^  e) {
			//проверяем, возможно ли добавить вратаря в данную команду
			//если да, он добавляется; иначе выводится сообщение об ошибке
			if (!playingField.add("goalkeeper", true, pictureBox1->Image->Size.Width / 2, pictureBox1->Image->Size.Height / 2)) {
				MessageBox::Show("Нельзя добавить более одного вратаря для одной команды");
			}

			//вызывается функция перерисовки игрового поля
			redraw_field();
		}

		//обработчик события нажатия на кнопку добавления красного защитника
		private: System::Void add_defender_right_Click(System::Object^  sender, System::EventArgs^  e) {
			//проверяем, возможно ли добавить защитника в данную команду
			//если да, он добавляется; иначе выводится сообщение об ошибке
			if (!playingField.add("defender", true, pictureBox1->Image->Size.Width / 2, pictureBox1->Image->Size.Height / 2)) {
				MessageBox::Show("Нельзя добавить более двух защитников для одной команды");
			}

			//вызывается функция перерисовки игрового поля
			redraw_field();
		}

		//обработчик события нажатия на кнопку добавления красного нападающего
		private: System::Void add_offensive_right_Click(System::Object^  sender, System::EventArgs^  e) {
			//проверяем, возможно ли добавить нападающего в данную команду
			//если да, он добавляется; иначе выводится сообщение об ошибке
			if (!playingField.add("offensive", true, pictureBox1->Image->Size.Width / 2, pictureBox1->Image->Size.Height / 2)) {
				MessageBox::Show("Нельзя добавить более трёх нападающих для одной команды");
			}

			//вызывается функция перерисовки игрового поля
			redraw_field();
		}

		//обработчик события нажатия на кнопку мыши
		private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			//проверка, что нажата правая кнопка, по которой происходит удаление игрока
			if (e->Button == System::Windows::Forms::MouseButtons::Right) {
				//координатам для удаления присваиваются нужные значения
				float x = e->X * pictureBox1->Image->Size.Width / pictureBox1->Size.Width;
				float y = e->Y * pictureBox1->Image->Size.Height / pictureBox1->Size.Height;
				//если данные координаты не указывают ни на какого игрока, выводится
				//сообщение об ошибке; иначе игрок удаляется с помощью метода удаления
				if (!playingField.del(x, y)) {
					MessageBox::Show("Неверные координаты игрока");
				}

				//вызывается функция перерисовки игрового поля
				redraw_field();
			}
		}

		//обработчик события начала нажатия кнопки мыши
		private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			//проверка, что нажата левая кнопка мыши
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				//координатам игрока присваиваются нужные значения
				float x = e->X * pictureBox1->Image->Size.Width / pictureBox1->Size.Width;
				float y = e->Y * pictureBox1->Image->Size.Height / pictureBox1->Size.Height;
				//вызывается метод начала перемещения игрока с данными координатами по полю
				playingField.start_moving(x, y);
			}
		}

		//обработчик события движения курсора мыши
		private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			//проверка, что нажата левая кнопка мыши
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				//координатам игрока присваиваются нужные значения
				float x = e->X * pictureBox1->Image->Size.Width / pictureBox1->Size.Width;
				float y = e->Y * pictureBox1->Image->Size.Height / pictureBox1->Size.Height;
				//вызывается метод перемещения игрока с данными координатами по полю; если игрока
				//можно переместить, поле перерисовывается
				if (playingField.move(x, y)) {
					redraw_field();
				}
			}
		}

		//обработчик события отпускания кнопки мыши
		private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			//проверка, что отпускается левая кнопка;
			//вызов метода окончания перемещения игрока
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				playingField.end_moving();
			}
		}
	};
}