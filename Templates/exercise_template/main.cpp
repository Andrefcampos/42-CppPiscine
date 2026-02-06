/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [your login] <[your email]>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: YYYY/MM/DD HH:MM:SS by [login]          #+#    #+#             */
/*   Updated: YYYY/MM/DD HH:MM:SS by [login]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassName.hpp"

int	main(void)
{
	// Test default constructor
	std::cout << "=== Test 1: Default Constructor ===" << std::endl;
	ClassName obj1;
	std::cout << obj1 << std::endl;
	std::cout << std::endl;

	// Test parameterized constructor
	std::cout << "=== Test 2: Parameterized Constructor ===" << std::endl;
	ClassName obj2(42, "test");
	std::cout << obj2 << std::endl;
	std::cout << std::endl;

	// Test copy constructor
	std::cout << "=== Test 3: Copy Constructor ===" << std::endl;
	ClassName obj3(obj2);
	std::cout << obj3 << std::endl;
	std::cout << std::endl;

	// Test assignment operator
	std::cout << "=== Test 4: Assignment Operator ===" << std::endl;
	obj1 = obj2;
	std::cout << obj1 << std::endl;
	std::cout << std::endl;

	// Test member functions
	std::cout << "=== Test 5: Member Functions ===" << std::endl;
	obj1.setPrivateVar(100);
	obj1.setPrivateName("updated");
	std::cout << "After setters: " << obj1 << std::endl;
	obj1.publicMethod();
	std::cout << std::endl;

	std::cout << "=== Destructors will be called ===" << std::endl;
	return (0);
}
