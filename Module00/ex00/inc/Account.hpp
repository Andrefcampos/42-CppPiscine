#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

# include <iostream>

class Account
{
	private:
		int		_id;
		int		_value;

		// Private constructor - only Bank can create accounts
		Account(int id);

		// Bank is friend to create and manage accounts
		friend class Bank;

	public:
		// Destructor
		~Account();

		// Const getters (by reference, not by copy)
		const int&	getId() const;
		const int&	getValue() const;

		// Overload << operator for output
		friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

#endif
