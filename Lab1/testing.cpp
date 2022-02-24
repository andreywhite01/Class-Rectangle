#include "testing.h"

ostream& operator<<(ostream& out, const pair<double, double>& p) {
	return out << "( " << p.first << ", " << p.second << " )";
}

void Test(const float& w, const float& h, const float& x, const float& y, const Rectangle& r) {
	Assert(r.GetParams(), vector<float>{ w, h, x, y }, "GetParams");
	Assert(r.GetPerimetr(), 2 * (w + h), "GetPerimetr");
	Assert(r.GetVertices(), vector<pair<float, float>>{
		{x - w / 2, y - h / 2},
		{ x - w / 2, y + h / 2 },
		{ x + w / 2, y + h / 2 },
		{ x + w / 2, y - h / 2 }}, "GetVertices");
}

void Test() {
	{
		Rectangle r(4, 2, 2., 1.);
		Assert(r.GetParams(), vector<float>{ 4, 2, 2, 1 }, "1");
		Assert(r.IsBoarder({ 0,1 }), true, "2");
		Assert(r.IsBoarder({ 0,3 }), false, "3");
		Assert(r.IsBoarder({ 1,1 }), false, "4");
		Assert(r.IsBoarder({ 4,2 }), true, "5");
		Assert(r.IsBoarder({ 3,3 }), false, "6");
		Assert(r.IsCrossesAbscissa(), true, "7");
		Assert(r.IsCrossesOrdinate(), true, "8");
	}
	{
		Rectangle r(4, 2, 1, 0);
		Assert(r.GetParams(), vector<float>{ 4, 2, 1, 0 }, "9");
		Assert(r.IsBoarder({ 0,1 }), true, "10");
		Assert(r.IsBoarder({ 0,3 }), false, "11");
		Assert(r.IsBoarder({ 1,1 }), true, "12");
		Assert(r.IsBoarder({ 3.006,1 }), false, "13");
		Assert(r.IsBoarder({ 3.005,1 }), true, "14");
		Assert(r.IsCrossesAbscissa(), true, "15");
		Assert(r.IsCrossesOrdinate(), true, "16");
	}
	{
		Rectangle r(4, 2, 7, 0);
		Assert(r.GetParams(), vector<float>{ 4, 2, 7, 0 }, "17");
		Assert(r.IsCrossesAbscissa(), true, "18");
		Assert(r.IsCrossesOrdinate(), false, "19");
	}
	{
		Rectangle r(4, 2, 0, 4);
		Assert(r.GetParams(), vector<float>{ 4, 2, 0, 4 }, "20");
		Assert(r.IsCrossesAbscissa(), false, "21");
		Assert(r.IsCrossesOrdinate(), true, "22");
	}
	{
		Rectangle r(4, 2, 0, 4);
		Assert(r.GetPerimetr(), 12, "21");
	}
	{
		Rectangle r(14, 3, -2, 3);
		Assert(r.GetPerimetr(), 34, "23");
	}
}