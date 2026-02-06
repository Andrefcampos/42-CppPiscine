#include "../inc/Vector2.hpp"

// Default constructor
Vector2::Vector2() : _x(0.0f), _y(0.0f)
{
}

// Parameterized constructor
Vector2::Vector2(float x, float y) : _x(x), _y(y)
{
}

// Copy constructor
Vector2::Vector2(const Vector2& other) : _x(other._x), _y(other._y)
{
}

// Destructor
Vector2::~Vector2()
{
}

// Assignment operator
Vector2&	Vector2::operator=(const Vector2& other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

// Getters
const float&	Vector2::getX() const
{
	return _x;
}

const float&	Vector2::getY() const
{
	return _y;
}

// Setters
void	Vector2::setX(float x)
{
	_x = x;
}

void	Vector2::setY(float y)
{
	_y = y;
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Vector2& v)
{
	os << "(" << v._x << ", " << v._y << ")";
	return os;
}
