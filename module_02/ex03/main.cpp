#include <iostream>
#include "Point.hpp"

int main() {
	Point a(0, 0), b(2, 0), c(0, 2);

	// Case 1: Point is inside the triangle
	Point point1(1, 0.5);
	if (bsp(a, b, c, point1)) {
		std::cout << "Point1 is inside the triangle." << std::endl;
	} else {
		std::cout << "Point1 is outside the triangle." << std::endl;
	}

	// Case 2: Point is on one of the vertices of the triangle
	Point point2(0, 0);
	if (bsp(a, b, c, point2)) {
		std::cout << "Point2 is inside the triangle." << std::endl;
	} else {
		std::cout << "Point2 is outside the triangle." << std::endl;
	}

	// Case 3: Point is on the edge of the triangle
	Point point3(1, 1);
	if (bsp(a, b, c, point3)) {
		std::cout << "Point3 is inside the triangle." << std::endl;
	} else {
		std::cout << "Point3 is outside the triangle." << std::endl;
	}

	// Case 4: Point is outside the triangle
	Point point4(2, 2);
	if (bsp(a, b, c, point4)) {
		std::cout << "Point4 is inside the triangle." << std::endl;
	} else {
		std::cout << "Point4 is outside the triangle." << std::endl;
	}

	return 0;
}
