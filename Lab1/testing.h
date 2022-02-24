#pragma once
#include "rectangle.h"

ostream& operator<<(ostream& out, const pair<double, double>& p);
template<class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[ ";
	auto it = v.begin();
	if (it != v.end())
	{
		while (next(it) != v.end())
		{
			out << *it << ", ";
			it++;
		}
		out << *it;
	}
	out << " ]";
	return out;
}
template <class T1, class T2>
void Assert(const T1& left, const T2& right, string hint) {
	if (left != right)
		cerr << "Ошибка в тесте " << hint << ": " << left << " != " << right << endl;
	else
		cerr << "Тест " << hint << " OK\n";
}
void Test();
void Test(const float& w, const float& h, const float& x, const float& y, const Rectangle& r);
