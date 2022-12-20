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

	//�������� ��������� ��� �������� ������� ������
	const float SIZE_PLAYER = 15.0F;

	//����� �����
	class Player {
	private:
		//��� ����
		//���������� x
		float x;
		//���������� y
		float y;
		//������� ���������� ��� �������� ���� �������
		bool team;
	public:
		//����� ����������� ����� ����������
		virtual void draw(Image ^image) = 0;

		//����� ����������� �����, ������������ ��� ������ � ���� ������
		virtual string get_type_player() = 0;

		//�����, ������������ ���������� x
		float get_x() {
			return x;
		}

		//�����, ������������ ���������� y
		float get_y() {
			return y;
		}

		//����� ��� ������������ ����������� �������� ������ ����� ��������
		void set_coordinates(float x, float y) {
			this->x = x;
			this->y = y;
		}

		//�����, ������������ ��� �������
		bool get_team() {
			return team;
		}

		//����� ��� ������������ ���� ������� �������� ������ ������ ����
		void set_team(bool team) {
			this->team = team;
		}
	};

	//����� ������� - ��������� ������ ����� 
	class Goalkeeper : public Player {
		//���������� ������������ ������, ������������� ��� ������
		virtual string get_type_player() {
			return "goalkeeper";
		}

		//���������� ������������ ������ ����������
		virtual void draw(Image ^image) {
			//��������� ��������� �� ������ ������ Graphics (����������� ����� FromImage()
			//������ Graphics ���������� ��������� �� ������ ������, ������� ��������� 
			//�������� �� ��������� � �������� ��������� �����������)
			Graphics^ g = Graphics::FromImage(image);
			//���� ������� ������� (�� ���� ������� get_team() ����� ������� true), ������
			//������� �������������, ������������ �������
			if (get_team()) {
				g->FillRectangle(Brushes::Red, get_x() - SIZE_PLAYER / 2, get_y() - SIZE_PLAYER / 2, SIZE_PLAYER, SIZE_PLAYER);
			}
			//���� ������� ����� (�� ���� ������� get_team() ����� ������� false), ������
			//����� �������������, ������������ �������
			else {
				g->FillRectangle(Brushes::Blue, get_x() - SIZE_PLAYER / 2, get_y() - SIZE_PLAYER / 2, SIZE_PLAYER, SIZE_PLAYER);
			}
		}
	};

	//����� �������� - ��������� ������ �����
	class Defender : public Player {
		//���������� ������������ ������, ������������� ��� ������
		virtual string get_type_player() {
			return "defender";
		}

		//���������� ������������ ������ ����������
		virtual void draw(Image ^image) {
			//��������� ��������� �� ������ ������ Graphics (����������� ����� FromImage()
			//������ Graphics ���������� ��������� �� ������ ������, ������� ��������� 
			//�������� �� ��������� � �������� ��������� �����������)
			Graphics^ g = Graphics::FromImage(image);
			//�������� ��������� �� ������ ������ �������������� (� ������ ������
			//�����, ������� ������������ ��������)
			cli::array<PointF> ^points = gcnew cli::array<PointF>(4);
			//������������ ���������� �������� ��������������� ��������
			points[0] = PointF(get_x(), get_y() - SIZE_PLAYER / 2);
			points[1] = PointF(get_x() - SIZE_PLAYER / 2, get_y());
			points[2] = PointF(get_x(), get_y() + SIZE_PLAYER / 2);
			points[3] = PointF(get_x() + SIZE_PLAYER / 2, get_y());

			//���� ������� ������� (�� ���� ������� get_team() ����� ������� true), ������
			//������� ����, ������������ ���������
			if (get_team()) {
				g->FillPolygon(Brushes::Red, points);
			}
			//���� ������� ����� (�� ���� ������� get_team() ����� ������� false), ������
			//����� ����, ������������ ���������
			else {
				g->FillPolygon(Brushes::Blue, points);
			}
		}
	};

	//����� ���������� - ��������� ������ �����
	class Offensive : public Player {
		//���������� ������������ ������, ������������� ��� ������
		virtual string get_type_player() {
			return "offensive";
		}

		//���������� ������������ ������ ����������
		virtual void draw(Image ^image) {
			//��������� ��������� �� ������ ������ Graphics (����������� ����� FromImage()
			//������ Graphics ���������� ��������� �� ������ ������, ������� ��������� 
			//�������� �� ��������� � �������� ��������� �����������)
			Graphics^ g = Graphics::FromImage(image);
			//�������� ��������� �� ������ ������ �������������� (� ������ ������
			//������������, ������� ������������ ��������)
			cli::array<PointF> ^points = gcnew cli::array<PointF>(3);
			//������������ ���������� �������� ��������������� ��������
			points[0] = PointF(get_x() - SIZE_PLAYER / 2, get_y() - SIZE_PLAYER / 2);
			points[1] = PointF(get_x() - SIZE_PLAYER / 2, get_y() + SIZE_PLAYER / 2);
			points[2] = PointF(get_x() + SIZE_PLAYER / 2, get_y());

			//���� ������� ������� (�� ���� ������� get_team() ����� ������� true), ������
			//������� �����������, ������������ �����������
			if (get_team()) {
				g->FillPolygon(Brushes::Red, points);
			}
			//���� ������� ����� (�� ���� ������� get_team() ����� ������� false), ������
			//����� �����������, ������������ �����������
			else {
				g->FillPolygon(Brushes::Blue, points);
			}
		}
	};

	//����� ���� ���������
	class PlayingField {
	private:
		//���� ������
		//������ ���������� �� ������� ������ �����
		vector<Player*> players;
		//���������� ��� �������� ������� ������������� �� ���� ������
		int index_moved_player;
	public:
		//� ������������ ��������� ��� �������� ������� ������������� �� ���� ������
		//������������� -1 (��������� ��������)
		PlayingField() {
			index_moved_player = -1;
		}

		//� ������������ ��������� ������ ��-��� ������� �������� �������
		~PlayingField() {
			for (int i = 0; i < players.size(); i++) {
				delete players[i];
			}
		}

		//����� ���������� ����� ���� (�������� - ��������� �� �����������, �� ���� �� ������ 
		//������ Image)
		void draw_field(Image^ image) {
			//� ����� ��� ������� ������ (������� �������� ������� players) ����������
			//����� ����������
			for (int i = 0; i < players.size(); i++) {
				players[i]->draw(image);
			}
		}

		//����� �������� ������� ������� ����
		//(��������� - ��� ������ � ��� �������)
		int counter(string type_player, bool type_team) {
			int count = 0;
			//� ����� ��������� ���������� ���� ������� ������ ������� � ������� ����
			for (int i = 0; i < players.size(); i++) {
				if ((players[i]->get_type_player() == type_player) && (players[i]->get_team() == type_team)) {
					count++;
				}
			}
			return count;
		}

		//����� ������ ������ � ��������� ������������ �� ����
		int find(float x, float y) {
			//� ����� �������������� �������� ��� ������� �������� �������: �������� �� ����� �
			//��������� ������������ � �������, ����������� ������-���� ������ �� �������
			//���� ����� ����� ������, ������������ ��� ������
			for (int i = 0; i < players.size(); i++) {
				if ((abs(players[i]->get_x() - x) <= SIZE_PLAYER / 2) && (abs(players[i]->get_y() - y) <= SIZE_PLAYER / 2)) {
					return i;
				}
			}
			//���� ����� ����� �� ��� ������, ������������ -1
			return -1;
		}

		//����� ���������� ������ ������
		//(���������: ��� ������, ��� �������, ���������� �����, � ������� ����� �������� ������)
		bool add(string type_player, bool type_team, float x, float y) {
			//������� � ������ ���������� �������
			if (type_player == "goalkeeper") {
				//������ ������ ������� � ������� ���� �� �����, ������� ������ �������� � �������
				//������ counter(), ��� �������� < 1 (����� ����� ���������)
				if (counter(type_player, type_team) < 1) {
					//�������� ��������� �� ������ ������ �������
					Goalkeeper* goalkeeper = new Goalkeeper();
					//������������ ������ ������� ���������� � ������� ���������
					goalkeeper->set_coordinates(x, y);
					//������������ ������ ������� ����������� � �������
					//���� �������
					goalkeeper->set_team(type_team);
					//���������� ������ ������ � ������
					players.push_back(goalkeeper);
					//���� ����� ��������, ������� ���������� true
					return true;
				}
				//���� ����� �� ��������, ������� ���������� false
				else {
					return false;
				}
			}
			//������� � ������ ���������� ���������
			else if (type_player == "defender") {
				//������ ���� ���������� � ������� ���� �� �����, ������� ������ �������� � �������
				//������ counter(), ��� ���������� < 2 (����� ����� ���������)
				if (counter(type_player, type_team) < 2) {
					//�������� ��������� �� ������ ������ ��������
					Defender* defender = new Defender();
					//������������ ������ ������� ���������� � ������� ���������
					defender->set_coordinates(x, y);
					//������������ ������ ������� ����������� � �������
					//���� �������
					defender->set_team(type_team);
					//���������� ������ ������ � ������
					players.push_back(defender);
					//���� ����� ��������, ������� ���������� true
					return true;
				}
				//���� ����� �� ��������, ������� ���������� false
				else {
					return false;
				}
			}
			//�������� � ������ ���������� �����������
			else if (type_player == "offensive") {
				//������ ��� ���������� � ������� ���� �� �����, ������� ������ �������� � �������
				//������ counter(), ��� ���������� < 3 (����� ����� ���������)
				if (counter(type_player, type_team) < 3) {
					//�������� ��������� �� ������ ������ ����������
					Offensive* offensive = new Offensive();
					//������������ ������ ������� ���������� � ������� ���������
					offensive->set_coordinates(x, y);
					//������������ ������ ������� ����������� � �������
					//���� �������
					offensive->set_team(type_team);
					//���������� ������ ������ � ������
					players.push_back(offensive);
					//���� ����� ��������, ������� ���������� true
					return true;
				}
				//���� ����� �� ��������, ������� ���������� false
				else {
					return false;
				}
			}
		}

		//������� �������� ������
		bool del(float x, float y) {
			//���������� � ���������� index �������� ������� find(x, y)
			int index = find(x, y);
			//���� ����� ������, ������� ������� ������; ������� ��������� �� ����� ������ ��
			//������� � ���������� true
			if (index != -1) {
				delete players[index];
				players.erase(players.begin() + index);
				return true;
			}
			//���� ����� �� ������, ������� ���������� false
			else {
				return false;
			}
		}

		//����� ������ ����������� ������ �� ����
		void start_moving(float x, float y) {
			//���������� index_moved_player ������������� �������� ������� �������������
			//������
			index_moved_player = find(x, y);
		}

		//����� ����������� ������
		bool move(float x, float y) {
			//���� ������ ������ -1, �� ���� ����� � ����������� � ������� ������������ �� ������,
			//������� ���������� false
			if (index_moved_player == -1) {
				return false;
			}
			//���� ����� ����� ������, �������� �� -1, ����������� ������ � ������ ��������
			//������������� �������� ���������� � ������� ���������, � �������
			//���������� true
			else {
				players[index_moved_player]->set_coordinates(x, y);
				return true;
			}
		}

		//����� ��������� �����������
		void end_moving() {
			//���������� ��� �������� ������� ������ ������������� �������� -1, ��� ���
			//����������� ���������
			index_moved_player = -1;
		}
	};

	//�������� ���������� ���������� - ������� ������ ������� ����
	PlayingField playingField;
}