#include "../inc/Graph.hpp"
#include "../inc/Vector2.hpp"
#include <iostream>

int main()
{
	std::cout << "=== CREATING GRAPH 5x5 ===" << std::endl;
	Graph graph(5.0f, 5.0f);

	std::cout << "\n=== ADDING POINTS ===" << std::endl;
	// Points from the subject example:
	// 0/0, 2/2, 4/2, 2/4
	graph.addPoint(0, 0);
	graph.addPoint(2, 2);
	graph.addPoint(4, 2);
	graph.addPoint(2, 4);

	std::cout << "\n=== GRAPH DISPLAY ===" << std::endl;
	graph.display();

	std::cout << "\n=== TESTING INVALID POINT ===" << std::endl;
	graph.addPoint(10, 10);  // Outside bounds

	std::cout << "\n=== TESTING VECTOR2 ===" << std::endl;
	Vector2 v1(3, 1);
	std::cout << "Vector v1: " << v1 << std::endl;
	std::cout << "v1.x = " << v1.getX() << ", v1.y = " << v1.getY() << std::endl;

	std::cout << "\n=== ADDING POINT USING VECTOR2 ===" << std::endl;
	graph.addPoint(v1);

	std::cout << "\n=== UPDATED GRAPH ===" << std::endl;
	graph.display();

	std::cout << "\n=== GRAPH INFO ===" << std::endl;
	std::cout << "Graph size: " << graph.getSize() << std::endl;
	std::cout << "Number of points: " << graph.getPointCount() << std::endl;

	std::cout << "\n=== TESTING ENCAPSULATION ===" << std::endl;
	std::cout << "Vector2 attributes are private (cannot access v1._x or v1._y)" << std::endl;
	std::cout << "Graph attributes are private (cannot access graph._size or graph._points)" << std::endl;
	
	// These lines would NOT compile (proving encapsulation works):
	// v1._x = 10;              // ERROR: _x is private
	// v1._y = 20;              // ERROR: _y is private
	// graph._size.setX(100);   // ERROR: _size is private
	// graph._points.clear();   // ERROR: _points is private

	std::cout << "\n=== END ===" << std::endl;
	return 0;
}
