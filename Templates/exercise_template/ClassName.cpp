/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassName.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [your login] <[your email]>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: YYYY/MM/DD HH:MM:SS by [login]          #+#    #+#             */
/*   Updated: YYYY/MM/DD HH:MM:SS by [login]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassName.hpp"

// Default constructor
ClassName::ClassName(void) : _privateVar(0), _privateName("default")
{
	std::cout << "ClassName default constructor called" << std::endl;
}

// Parameterized constructor
ClassName::ClassName(int value, std::string const &name)
	: _privateVar(value), _privateName(name)
{
	std::cout << "ClassName parameterized constructor called" << std::endl;
}

// Copy constructor
ClassName::ClassName(ClassName const &src)
{
	std::cout << "ClassName copy constructor called" << std::endl;
	*this = src;
}

// Assignment operator
ClassName &ClassName::operator=(ClassName const &rhs)
{
	std::cout << "ClassName assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_privateVar = rhs._privateVar;
		this->_privateName = rhs._privateName;
	}
	return (*this);
}

// Destructor
ClassName::~ClassName(void)
{
	std::cout << "ClassName destructor called" << std::endl;
}

// Getters
int	ClassName::getPrivateVar(void) const
{
	return (this->_privateVar);
}

std::string	ClassName::getPrivateName(void) const
{
	return (this->_privateName);
}

// Setters
void	ClassName::setPrivateVar(int value)
{
	this->_privateVar = value;
}

void	ClassName::setPrivateName(std::string const &name)
{
	this->_privateName = name;
}

// Other member functions
void	ClassName::publicMethod(void)
{
	std::cout << "Public method called" << std::endl;
}

// Overload insertion operator
std::ostream &operator<<(std::ostream &out, ClassName const &obj)
{
	out << "ClassName { var: " << obj.getPrivateVar() 
		<< ", name: " << obj.getPrivateName() << " }";
	return (out);
}
