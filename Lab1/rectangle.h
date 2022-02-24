#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <exception>
#include <algorithm>

#define PRECISION 0.005
using namespace std;

class Rectangle
{
public:

	//Конструктор
	Rectangle(const float& w, const float& h, const float& x, const float& y);

	//Возвращает параметры фигуры (длина одной стороны, второй, координаты центра)
	vector<float> GetParams() const;

	//Возвращает true, если точка принадлежит границе, иначе false
	bool IsBoarder(const pair<float, float>& point) const;

	//Возвращает true, если фигура пересекает ось абсцисс, в противном случае false
	bool IsCrossesAbscissa() const;

	//Возвращает true, если фигура пересекает ось ординат, в противном случае false
	bool IsCrossesOrdinate() const;

	//Возвращает периметр фигуры
	float GetPerimetr() const;

	//Возвращает координаты вершин фигуры
	vector<pair<float, float>> GetVertices() const;

private:

	//Возвращает расстояние от точки p0 до прямой, построенной по двух точкам p1 и p2
	float DistancePointLine(const pair<float, float>& p0,
		const pair<float, float>& p1, const pair<float, float>& p2) const;

	//Расстояние между точками
	float DistanceBetweenPoints(const pair<float, float>& p1, const pair<float, float>& p2) const;

	//длина нижней стороны
	const float width;

	//длина боковой стороны
	const float height;

	//абсцисса центра
	const float center_x;

	//ордината центра
	const float center_y;

	//абсциссы всех вершин фигуры
	vector<float> vertices_x;

	//ординаты всех вершин фигуры
	vector<float> vertices_y;

	//координаты вершин фигуры
	vector<pair<float, float>> vertices;
};
