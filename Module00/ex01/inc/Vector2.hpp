#ifndef VECTOR2_HPP
# define VECTOR2_HPP

# include <iostream>

class Vector2
{
	private:
		float	_x;
		float	_y;

	public:
		// Constructors
		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector2& other);
		~Vector2();

		// Assignment operator
		Vector2&	operator=(const Vector2& other);

		// Getters (const by reference)
		const float&	getX() const;
		const float&	getY() const;

		// Setters
		void	setX(float x);
		void	setY(float y);

		// Overload << operator for output
		friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
};

#endif
