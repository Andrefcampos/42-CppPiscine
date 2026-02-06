#include "../inc/Graph.hpp"

// Constructor with width and height
Graph::Graph(float width, float height) : _size(width, height)
{
}

// Constructor with Vector2
Graph::Graph(const Vector2& size) : _size(size)
{
}

// Destructor
Graph::~Graph()
{
}

// Get size
const Vector2&	Graph::getSize() const
{
	return _size;
}

// Private helper: check if point is within graph bounds
bool	Graph::_isPointValid(const Vector2& point) const
{
	return (point.getX() >= 0 && point.getX() <= _size.getX() &&
			point.getY() >= 0 && point.getY() <= _size.getY());
}

// Add point with x, y coordinates
bool	Graph::addPoint(float x, float y)
{
	Vector2 point(x, y);
	return addPoint(point);
}

// Add point with Vector2
bool	Graph::addPoint(const Vector2& point)
{
	if (!_isPointValid(point))
	{
		std::cout << "Error: Point " << point 
				  << " is outside graph bounds (0-" << _size.getX() 
				  << ", 0-" << _size.getY() << ")" << std::endl;
		return false;
	}
	_points.push_back(point);
	return true;
}

// Get number of points
size_t	Graph::getPointCount() const
{
	return _points.size();
}

// Display graph as ASCII art
void	Graph::display() const
{
	int width = static_cast<int>(_size.getX());
	int height = static_cast<int>(_size.getY());

	// Display from top to bottom (Y axis reversed for display)
	for (int y = height; y >= 0; y--)
	{
		std::cout << ">& " << y << " ";
		
		for (int x = 0; x <= width; x++)
		{
			bool pointFound = false;
			
			// Check if there's a point at this position
			for (size_t i = 0; i < _points.size(); i++)
			{
				if (static_cast<int>(_points[i].getX()) == x && 
					static_cast<int>(_points[i].getY()) == y)
				{
					pointFound = true;
					break;
				}
			}
			
			if (pointFound)
				std::cout << "X ";
			else
				std::cout << ". ";
		}
		std::cout << std::endl;
	}
	
	// Display X axis labels
	std::cout << ">& ";
	for (int x = 0; x <= width; x++)
		std::cout << "  ";
	std::cout << std::endl;
	
	std::cout << ">& ";
	for (int x = 0; x <= width; x++)
		std::cout << x << " ";
	std::cout << std::endl;
}
