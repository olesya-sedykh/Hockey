#pragma once
#include <string>
#include <vector>

namespace Hockey {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	//создание константы для хранения размера игрока
	const float SIZE_PLAYER = 15.0F;

	//класс Игрок
	class Player {
	private:
		//его поля
		//координата x
		float x;
		//координата y
		float y;
		//булевая переменная для хранения типа команды
		bool team;
	public:
		//чисто виртуальный метод прорисовки
		virtual void draw(Image ^image) = 0;

		//чисто виртуальный метод, возвращающий тип игрока в виде строки
		virtual string get_type_player() = 0;

		//метод, возвращающий координату x
		float get_x() {
			return x;
		}

		//метод, возвращающий координату y
		float get_y() {
			return y;
		}

		//метод для присваивания координатам текущего игрока новых значений
		void set_coordinates(float x, float y) {
			this->x = x;
			this->y = y;
		}

		//метод, возвращающий тип команды
		bool get_team() {
			return team;
		}

		//метод для присваивания типу команды текущего игрока нового типа
		void set_team(bool team) {
			this->team = team;
		}
	};

	//класс Вратарь - наследник класса Игрок 
	class Goalkeeper : public Player {
		//реализация виртуального метода, возвращающего тип игрока
		virtual string get_type_player() {
			return "goalkeeper";
		}

		//реализация виртуального метода прорисовки
		virtual void draw(Image ^image) {
			//получение указателя на объект класса Graphics (статический метод FromImage()
			//класса Graphics возвращает указатель на объект класса, который позволяет 
			//рисовать на указанном в качестве параметра изображении)
			Graphics^ g = Graphics::FromImage(image);
			//если команда красная (то есть функция get_team() имеет значени true), рисуем
			//красный прямоугольник, обозначающий вратаря
			if (get_team()) {
				g->FillRectangle(Brushes::Red, get_x() - SIZE_PLAYER / 2, get_y() - SIZE_PLAYER / 2, SIZE_PLAYER, SIZE_PLAYER);
			}
			//если команда синяя (то есть функция get_team() имеет значени false), рисуем
			//синий прямоугольник, обозначающий вратаря
			else {
				g->FillRectangle(Brushes::Blue, get_x() - SIZE_PLAYER / 2, get_y() - SIZE_PLAYER / 2, SIZE_PLAYER, SIZE_PLAYER);
			}
		}
	};

	//класс Защитник - наследник класса Игрок
	class Defender : public Player {
		//реализация виртуального метода, возвращающего тип игрока
		virtual string get_type_player() {
			return "defender";
		}

		//реализация виртуального метода прорисовки
		virtual void draw(Image ^image) {
			//получение указателя на объект класса Graphics (статический метод FromImage()
			//класса Graphics возвращает указатель на объект класса, который позволяет 
			//рисовать на указанном в качестве параметра изображении)
			Graphics^ g = Graphics::FromImage(image);
			//создание указателя на массив вершин многоугольника (в данном случае
			//ромба, которым обозначается защитник)
			cli::array<PointF> ^points = gcnew cli::array<PointF>(4);
			//присваивание координтам вершинам соответствующих значений
			points[0] = PointF(get_x(), get_y() - SIZE_PLAYER / 2);
			points[1] = PointF(get_x() - SIZE_PLAYER / 2, get_y());
			points[2] = PointF(get_x(), get_y() + SIZE_PLAYER / 2);
			points[3] = PointF(get_x() + SIZE_PLAYER / 2, get_y());

			//если команда красная (то есть функция get_team() имеет значени true), рисуем
			//красный ромб, обозначающий защитника
			if (get_team()) {
				g->FillPolygon(Brushes::Red, points);
			}
			//если команда синяя (то есть функция get_team() имеет значени false), рисуем
			//синий ромб, обозначающий защитника
			else {
				g->FillPolygon(Brushes::Blue, points);
			}
		}
	};

	//класс Нападающий - наследник класса Игрок
	class Offensive : public Player {
		//реализация виртуального метода, возвращающего тип игрока
		virtual string get_type_player() {
			return "offensive";
		}

		//реализация виртуального метода прорисовки
		virtual void draw(Image ^image) {
			//получение указателя на объект класса Graphics (статический метод FromImage()
			//класса Graphics возвращает указатель на объект класса, который позволяет 
			//рисовать на указанном в качестве параметра изображении)
			Graphics^ g = Graphics::FromImage(image);
			//создание указателя на массив вершин многоугольника (в данном случае
			//треугольника, которым обозначается защитник)
			cli::array<PointF> ^points = gcnew cli::array<PointF>(3);
			//присваивание координтам вершинам соответствующих значений
			points[0] = PointF(get_x() - SIZE_PLAYER / 2, get_y() - SIZE_PLAYER / 2);
			points[1] = PointF(get_x() - SIZE_PLAYER / 2, get_y() + SIZE_PLAYER / 2);
			points[2] = PointF(get_x() + SIZE_PLAYER / 2, get_y());

			//если команда красная (то есть функция get_team() имеет значени true), рисуем
			//красный треугольник, обозначающий нападающего
			if (get_team()) {
				g->FillPolygon(Brushes::Red, points);
			}
			//если команда синяя (то есть функция get_team() имеет значени false), рисуем
			//синий треугольник, обозначающий нападающего
			else {
				g->FillPolygon(Brushes::Blue, points);
			}
		}
	};

	//класс Поле рисования
	class PlayingField {
	private:
		//поля класса
		//вектор указателей на объекты класса Игрок
		vector<Player*> players;
		//переменная для хранения индекса перемещаемого по полю игрока
		int index_moved_player;
	public:
		//в конструкторе перменной для хранения индекса перемещаемого по полю игрока
		//присваивается -1 (начальное значение)
		PlayingField() {
			index_moved_player = -1;
		}

		//в декструкторе очищается память из-под каждого элемента вектора
		~PlayingField() {
			for (int i = 0; i < players.size(); i++) {
				delete players[i];
			}
		}

		//метод прорисовки всего поля (параметр - указатель на изображение, то есть на объект 
		//класса Image)
		void draw_field(Image^ image) {
			//в цикле для каждого игрока (каждого элемента вектора players) вызывается
			//метод прорисовки
			for (int i = 0; i < players.size(); i++) {
				players[i]->draw(image);
			}
		}

		//метод подсчёта игроков каждого вида
		//(параметры - тип игрока и тип команды)
		int counter(string type_player, bool type_team) {
			int count = 0;
			//в цикле считается количество всех игроков данной команды и данного типа
			for (int i = 0; i < players.size(); i++) {
				if ((players[i]->get_type_player() == type_player) && (players[i]->get_team() == type_team)) {
					count++;
				}
			}
			return count;
		}

		//метод поиска игрока с заданными координатами на поле
		int find(float x, float y) {
			//в цикле осуществляется проверка для каждого элемента вектора: попадает ли игрок с
			//заданными координатами в область, накрывающую какого-либо игрока из вектора
			//если такой игрок найден, возвращается его индекс
			for (int i = 0; i < players.size(); i++) {
				if ((abs(players[i]->get_x() - x) <= SIZE_PLAYER / 2) && (abs(players[i]->get_y() - y) <= SIZE_PLAYER / 2)) {
					return i;
				}
			}
			//если такой игрок не был найден, возвращается -1
			return -1;
		}

		//метод добавления нового игрока
		//(параметры: тип игрока, тип команды, координаты точки, в которую нужно добавить игрока)
		bool add(string type_player, bool type_team, float x, float y) {
			//дествия в случае добавления вратаря
			if (type_player == "goalkeeper") {
				//больше одного вратаря в команде быть не может, поэтому делаем проверку с помощью
				//метода counter(), что вратарей < 1 (тогда можно добавлять)
				if (counter(type_player, type_team) < 1) {
					//создание указателя на объект класса Вратарь
					Goalkeeper* goalkeeper = new Goalkeeper();
					//присваивание новому объекту переданных в функцию координат
					goalkeeper->set_coordinates(x, y);
					//присваивание новому объекту переданного в функцию
					//типа команды
					goalkeeper->set_team(type_team);
					//добавление нового игрока в вектор
					players.push_back(goalkeeper);
					//если игрок добавлен, функция возвращает true
					return true;
				}
				//если игрок не добавлен, функция возвращает false
				else {
					return false;
				}
			}
			//дествия в случае добавления защитника
			else if (type_player == "defender") {
				//больше двух защитников в команде быть не может, поэтому делаем проверку с помощью
				//метода counter(), что защитников < 2 (тогда можно добавлять)
				if (counter(type_player, type_team) < 2) {
					//создание указателя на объект класса Защитник
					Defender* defender = new Defender();
					//присваивание новому объекту переданных в функцию координат
					defender->set_coordinates(x, y);
					//присваивание новому объекту переданного в функцию
					//типа команды
					defender->set_team(type_team);
					//добавление нового игрока в вектор
					players.push_back(defender);
					//если игрок добавлен, функция возвращает true
					return true;
				}
				//если игрок не добавлен, функция возвращает false
				else {
					return false;
				}
			}
			//действия в случае добавления нападающего
			else if (type_player == "offensive") {
				//больше трёх нападающих в команде быть не может, поэтому делаем проверку с помощью
				//метода counter(), что нападающих < 3 (тогда можно добавлять)
				if (counter(type_player, type_team) < 3) {
					//создание указателя на объект класса Нападающий
					Offensive* offensive = new Offensive();
					//присваивание новому объекту переданных в функцию координат
					offensive->set_coordinates(x, y);
					//присваивание новому объекту переданного в функцию
					//типа команды
					offensive->set_team(type_team);
					//добавление нового игрока в вектор
					players.push_back(offensive);
					//если игрок добавлен, функция возвращает true
					return true;
				}
				//если игрок не добавлен, функция возвращает false
				else {
					return false;
				}
			}
		}

		//функция удаления игрока
		bool del(float x, float y) {
			//записываем в переменную index значение функции find(x, y)
			int index = find(x, y);
			//если игрок найден, функция удаляет игрока; удаляет указатель на этого игрока из
			//вектора и возвращает true
			if (index != -1) {
				delete players[index];
				players.erase(players.begin() + index);
				return true;
			}
			//если игрок не найден, функция возвращает false
			else {
				return false;
			}
		}

		//метод начала перемещения игрока по полю
		void start_moving(float x, float y) {
			//переменной index_moved_player присваивается значение индекса перемещаемого
			//игрока
			index_moved_player = find(x, y);
		}

		//метод перемещения игрока
		bool move(float x, float y) {
			//если индекс игрока -1, то есть игрок с переданными в функцию координатами не найден,
			//функция возвращает false
			if (index_moved_player == -1) {
				return false;
			}
			//если игрок имеет индекс, отличный от -1, координатам игрока с данным индексом
			//присваиваются значения переданных в функцию координат, и функция
			//возвращает true
			else {
				players[index_moved_player]->set_coordinates(x, y);
				return true;
			}
		}

		//метод окончания перемещения
		void end_moving() {
			//переменной для хранения индекса игрока присваивается значение -1, так как
			//перемещение завершено
			index_moved_player = -1;
		}
	};

	//создание глобальной переменной - объекта класса Игровое поле
	PlayingField playingField;
}