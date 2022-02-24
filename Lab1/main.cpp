#include <iostream>
#include <map>
#include "rectangle.h"
#include "testing.h"
using namespace std;

void UserTasting();
void TestingFigure(shared_ptr<Rectangle> fig);

int main() {
	setlocale(LC_ALL, "russian");
	Test();
	UserTasting();
	return 0;
}

void TextInfo() {
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Вы можете создать новый прямоугольник с помощью команды:\n\n";
	cout << "RECT a b x y - прямоульник со сторонами a, b и координатами центра (x,y)\n\n";

	cout << "Тестировать фигуру Вы можете с помощью команд:\n\n";
	cout << "1) BOARD x y - является ли точка граничной\n";
	cout << "2) ABS - пересекает ли фигура ось абсцисс\n";
	cout << "3) ORD - пересекает ли фигура ось ординат\n";
	cout << "4) VERT - выводит координаты вершин фигуры\n";
	cout << "5) PERIM - выводит периметр фигуры\n";
	cout << "6) NEW - удалить текущую фигуру и создать новую\n\n";

	cout << "INFO - еще раз вывести эту информацию\n";
	cout << "EXIT - завершить программу\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
}

enum class CREAT_OPS {
	EXIT,
	INFO,
	RECT,
};

enum class TEST_OPS {
	NEW,
	BOARD,
	ABS,
	ORD,
	VERT,
	PERIM,
	ORIG,
};

void UserTasting() {
	TextInfo();
	map<string, int> creat_ops = {
		{"EXIT",0},
		{"INFO",1},
		{"RECT",2} };


	string op = "";

	while (op != "EXIT") {
		cout << "<< ";
		cin >> op;
		if (creat_ops.find(op) != creat_ops.end())
		{
			CREAT_OPS operation = (CREAT_OPS)creat_ops[op];
			switch (operation)
			{
			case CREAT_OPS::EXIT: {
				return;
				break;
			}
			case CREAT_OPS::INFO: {
				TextInfo();
				break;
			}
			case CREAT_OPS::RECT: {
				float w, h, x, y;
				cin >> w >> h >> x >> y;
				Rectangle fig(w, h, x, y);
				cout << "Прямоугольник создан\n";
				TestingFigure(make_shared<Rectangle>(fig));
				break;
			}
			default: {
				break;
			}
			}
		}
		else {
			cout << "Сначала необходимо создать фигуру\n";
		}
	}
}


void TestingFigure(shared_ptr<Rectangle> fig) {
	map<string, int> test_ops = {
		{"NEW",0},
		{"BOARD", 1},
		{"ABS",2},
		{"ORD",3},
		{"VERT",4},
		{"PERIM",5},
		{"ORIG",6} };
	string op;
	while (op != "NEW") {
		cout << "\t>>";
		cin >> op;
		if (test_ops.find(op) != test_ops.end())
		{
			TEST_OPS operation = (TEST_OPS)test_ops[op];
			switch (operation)
			{
			case TEST_OPS::NEW: {
				cout << "\tВы действительно хотите удалить текущую фигру и создать новую? Y - согласие, другой символ - отмена\n";
				char answ;
				cout << "\t>>";
				cin >> answ;
				if (answ == 'Y') {
					cout << "\tФигруа удалена\n";
					return;
				}
				else {
					op = "";
					break;
				}
			}
			case TEST_OPS::BOARD: {
				float x, y;
				cin >> x >> y;
				if (fig->IsBoarder({ x, y }))
					cout << "\tTRUE\n";
				else
					cout << "\tFALSE\n";
				break;
			}
			case TEST_OPS::ABS: {
				if (fig->IsCrossesAbscissa())
					cout << "\tTRUE\n";
				else
					cout << "\tFALSE\n";
				break;
			}
			case TEST_OPS::ORD: {
				if (fig->IsCrossesOrdinate())
					cout << "\tTRUE\n";
				else
					cout << "\tFALSE\n";
				break;
			}
			case TEST_OPS::VERT: {
				cout << "\tВершины фигуры:\t" << fig->GetVertices() << endl;
				break;
			}
			case TEST_OPS::PERIM: {
				cout << "\tПериметр фигуры:\t" << fig->GetPerimetr() << endl;
				break;
			}
			default:
				cout << "\tВы ввели несуществующую команду, введите INFO, чтобы получить список команд\n";
				break;
			}
		}
		else
			cout << "Неизвестная команда\n";
	}
}