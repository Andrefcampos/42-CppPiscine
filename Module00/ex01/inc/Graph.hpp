#ifndef GRAPH_HPP
# define GRAPH_HPP

# include "Vector2.hpp"
# include <vector>
# include <iostream>

class Graph
{
	private:
		Vector2					_size;
		std::vector<Vector2>	_points;

		// Private helper method to check if point is valid
		bool	_isPointValid(const Vector2& point) const;

	public:
		// Constructor
		Graph(float width, float height);
		Graph(const Vector2& size);
		~Graph();

		// Getters
		const Vector2&	getSize() const;
		
		// Add point to graph
		bool	addPoint(float x, float y);
		bool	addPoint(const Vector2& point);

		// Display graph on console
		void	display() const;

		// Get number of points
		size_t	getPointCount() const;
};

#endif
