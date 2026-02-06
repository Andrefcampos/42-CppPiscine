#include "../inc/Bank.hpp"

Bank::Bank() : _liquidity(0), _nextAccountId(0)
{
}

Bank::~Bank()
{
	// Clean up all accounts
	for (size_t i = 0; i < _clientAccounts.size(); i++)
		delete _clientAccounts[i];
	_clientAccounts.clear();
}

// Const getter for liquidity
const int&	Bank::getLiquidity() const
{
	return _liquidity;
}

// Private helper: find account by ID
Account*	Bank::_findAccountById(int id)
{
	for (size_t i = 0; i < _clientAccounts.size(); i++)
	{
		if (_clientAccounts[i]->_id == id)
			return _clientAccounts[i];
	}
	return NULL;
}

// Private helper: check if account ID exists
bool	Bank::_accountIdExists(int id) const
{
	for (size_t i = 0; i < _clientAccounts.size(); i++)
	{
		if (_clientAccounts[i]->_id == id)
			return true;
	}
	return false;
}

// Create a new account with unique ID
Account*	Bank::createAccount()
{
	Account* newAccount = new Account(_nextAccountId);
	_clientAccounts.push_back(newAccount);
	_nextAccountId++;
	std::cout << "Account [" << newAccount->_id << "] created" << std::endl;
	return newAccount;
}

// Delete account by ID
void	Bank::deleteAccount(int accountId)
{
	for (size_t i = 0; i < _clientAccounts.size(); i++)
	{
		if (_clientAccounts[i]->_id == accountId)
		{
			std::cout << "Account [" << accountId << "] deleted" << std::endl;
			delete _clientAccounts[i];
			_clientAccounts.erase(_clientAccounts.begin() + i);
			return;
		}
	}
	std::cout << "Error: Account [" << accountId << "] not found" << std::endl;
}

// Deposit money to account (bank takes 5% fee)
bool	Bank::deposit(int accountId, int amount)
{
	if (amount <= 0)
	{
		std::cout << "Error: Invalid deposit amount" << std::endl;
		return false;
	}

	Account* account = _findAccountById(accountId);
	if (!account)
	{
		std::cout << "Error: Account [" << accountId << "] not found" << std::endl;
		return false;
	}

	// Bank takes 5% of the deposit
	int bankFee = amount * 0.05;
	int clientAmount = amount - bankFee;

	account->_value += clientAmount;
	_liquidity += bankFee;

	std::cout << "Deposited " << amount << " to account [" << accountId 
			  << "] (Bank fee: " << bankFee << ", Client receives: " 
			  << clientAmount << ")" << std::endl;
	return true;
}

// Withdraw money from account
bool	Bank::withdraw(int accountId, int amount)
{
	if (amount <= 0)
	{
		std::cout << "Error: Invalid withdrawal amount" << std::endl;
		return false;
	}

	Account* account = _findAccountById(accountId);
	if (!account)
	{
		std::cout << "Error: Account [" << accountId << "] not found" << std::endl;
		return false;
	}

	if (account->_value < amount)
	{
		std::cout << "Error: Insufficient funds in account [" << accountId << "]" << std::endl;
		return false;
	}

	account->_value -= amount;
	std::cout << "Withdrawn " << amount << " from account [" << accountId << "]" << std::endl;
	return true;
}

// Give loan to account (within bank's liquidity limits)
bool	Bank::giveLoan(int accountId, int amount)
{
	if (amount <= 0)
	{
		std::cout << "Error: Invalid loan amount" << std::endl;
		return false;
	}

	Account* account = _findAccountById(accountId);
	if (!account)
	{
		std::cout << "Error: Account [" << accountId << "] not found" << std::endl;
		return false;
	}

	if (_liquidity < amount)
	{
		std::cout << "Error: Bank has insufficient liquidity for loan of " 
				  << amount << " (Available: " << _liquidity << ")" << std::endl;
		return false;
	}

	account->_value += amount;
	_liquidity -= amount;

	std::cout << "Loan of " << amount << " granted to account [" << accountId << "]" << std::endl;
	return true;
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Bank& bank)
{
	os << "Bank informations :" << std::endl;
	os << "Liquidity : " << bank._liquidity << std::endl;
	for (size_t i = 0; i < bank._clientAccounts.size(); i++)
		os << *bank._clientAccounts[i] << std::endl;
	return os;
}
