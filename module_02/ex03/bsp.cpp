#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Point ab = b - a;
	Point bp = point - b;

	Point bc = c - b;
	Point cp = point - c;

	Point ca = a - c;
	Point ap = point - a;

	float c1 = ab * bp;
	float c2 = bc * cp;
	float c3 = ca * ap;

	return (c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0);
}
