#ifndef BANK_HPP
# define BANK_HPP

# include "Account.hpp"
# include <vector>
# include <iostream>

class Bank
{
	private:
		int						_liquidity;
		std::vector<Account*>	_clientAccounts;
		int						_nextAccountId;

		// Private helper methods
		Account*	_findAccountById(int id);
		bool		_accountIdExists(int id) const;

	public:
		// Constructor and Destructor
		Bank();
		~Bank();

		// Const getters (by reference, not by copy)
		const int&	getLiquidity() const;

		// Account management
		Account*	createAccount();
		void		deleteAccount(int accountId);
		
		// Banking operations
		bool		deposit(int accountId, int amount);
		bool		withdraw(int accountId, int amount);
		bool		giveLoan(int accountId, int amount);

		// Overload << operator for output
		friend std::ostream& operator<<(std::ostream& os, const Bank& bank);
};

#endif
