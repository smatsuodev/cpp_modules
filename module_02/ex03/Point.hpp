#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &point);
	~Point();
	Point &operator=(const Point &point);
	Point operator+(const Point &rhs) const;
	Point operator-(const Point &rhs) const;
	float operator*(const Point &rhs) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
