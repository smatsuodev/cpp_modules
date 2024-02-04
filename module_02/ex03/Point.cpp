#include "Point.hpp"

Point::Point() {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &point) {
	*this = point;
}

Point::~Point() {}

Point &Point::operator=(const Point &point) {
	*const_cast<Fixed *>(&this->x) = point.x;
	*const_cast<Fixed *>(&this->y) = point.y;

	return *this;
}

Point Point::operator+(const Point &rhs) const {
	return Point((this->x + rhs.x).toFloat(), (this->y + rhs.y).toFloat());
}

Point Point::operator-(const Point &rhs) const {
	return Point((this->x - rhs.x).toFloat(), (this->y - rhs.y).toFloat());
}

float Point::operator*(const Point &rhs) const {
	return (this->x * rhs.y - this->y * rhs.x).toFloat();
}
