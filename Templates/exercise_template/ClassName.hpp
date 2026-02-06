/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassName.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [your login] <[your email]>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: YYYY/MM/DD HH:MM:SS by [login]          #+#    #+#             */
/*   Updated: YYYY/MM/DD HH:MM:SS by [login]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSNAME_HPP
# define CLASSNAME_HPP

# include <iostream>
# include <string>

class ClassName
{
private:
	// Private member variables (prefix with _)
	int			_privateVar;
	std::string	_privateName;

public:
	// Orthodox Canonical Form
	ClassName(void);								// Default constructor
	ClassName(ClassName const &src);				// Copy constructor
	ClassName &operator=(ClassName const &rhs);		// Assignment operator
	~ClassName(void);								// Destructor

	// Parameterized constructor (if needed)
	ClassName(int value, std::string const &name);

	// Getters
	int			getPrivateVar(void) const;
	std::string	getPrivateName(void) const;

	// Setters
	void		setPrivateVar(int value);
	void		setPrivateName(std::string const &name);

	// Other member functions
	void		publicMethod(void);
};

// Overload insertion operator for output (if needed)
std::ostream &operator<<(std::ostream &out, ClassName const &obj);

#endif
