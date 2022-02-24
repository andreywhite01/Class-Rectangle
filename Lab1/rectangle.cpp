#include "Rectangle.h"
Rectangle::Rectangle(const float& w, const float& h, const float& x, const float& y) :
	width(w), height(h),
	center_x(x), center_y(y) {
	try
	{
		if (width <= 0)
			throw exception("Нижняя сторона фигуры должна быть больше нуля!");
		else if (height <= 0)
			throw exception("Боковая сторона фигуры должна быть больше нуля!");
	}
	catch (const exception& e)
	{
		cerr << "Не удалось создать объект: " << e.what();
	}
	vertices_x = { center_x - width / 2,
		center_x - width / 2,
		center_x + width / 2,
		center_x + width / 2 };
	vertices_y = { center_y - height / 2,
		center_y + height / 2,
		center_y + height / 2,
		center_y - height / 2 };
	for (unsigned int i = 0; i < vertices_x.size(); ++i) {
		vertices.push_back({ vertices_x[i], vertices_y[i] });
	}
}

vector<float> Rectangle::GetParams() const {
	vector<float> params = {
		round(width * 1000) / 1000.f,
		round(height * 1000) / 1000.f,
		round(center_x * 1000) / 1000.f,
		round(center_y * 1000) / 1000.f };
	return params;
}

bool Rectangle::IsBoarder(const pair<float, float>& point) const {
	float x = point.first;
	float y = point.second;
	pair<float, float> p0 = { x, y };
	vector<pair<float, float>> vertices = GetVertices();
	vertices.push_back(vertices[0]);
	for (unsigned int i = 0; i < vertices.size() - 1; ++i) {
		// Если расстояние от точки до одной из сторон фигру меньше 0,005
		if (round(DistancePointLine(p0, vertices[i], vertices[i + 1]) * 1000) / 1000.f < PRECISION) {
			float len_1 = DistanceBetweenPoints(p0, vertices[i]),
				len_2 = DistanceBetweenPoints(p0, vertices[i + 1]),
				len_3 = DistanceBetweenPoints(vertices[i], vertices[i + 1]);
			// Если эта точка действительно лежит на границе, а не на продолжении стороны 
			if (round(max(len_1, len_2) * 1000) <= round(len_3 * 1000))
				return true;
		}
	}
	return false;
}

bool Rectangle::IsCrossesAbscissa() const {
	//Фигура пересекает ось абсции, если ординаты любых двух вершин имеют разные знаки
	return ((*min_element(vertices_y.begin(), vertices_y.end())) * (*max_element(vertices_y.begin(), vertices_y.end()))) <= 0;
}

bool Rectangle::IsCrossesOrdinate() const {
	//Фигура пересекает ось ординат, если абсциссы любых двух вершин имеют разные знаки
	return ((*min_element(vertices_x.begin(), vertices_x.end())) * (*max_element(vertices_x.begin(), vertices_x.end()))) <= 0;
}

float Rectangle::GetPerimetr() const {
	return 2 * (width + height);
}

float Rectangle::DistanceBetweenPoints(const pair<float, float>& p1, const pair<float, float>& p2) const {
	float x1 = p1.first,
		y1 = p1.second,
		x2 = p2.first,
		y2 = p2.second;
	float distance = (float)sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return distance;
}

float Rectangle::DistancePointLine(const pair<float, float>& p0,
	const pair<float, float>& p1, const pair<float, float>& p2) const {
	float x0 = p0.first,
		y0 = p0.second,
		x1 = p1.first,
		y1 = p1.second,
		x2 = p2.first,
		y2 = p2.second;
	float distance = abs((y2 - y1) * x0 - (x2 - x1) * y0 - x1 * (y2 - y1) + y1 * (x2 - x1)) /
		(float)sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
	return distance;
}

vector<pair<float, float>> Rectangle::GetVertices() const {
	return vertices;
}