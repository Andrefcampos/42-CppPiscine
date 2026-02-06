#include "../inc/Bank.hpp"
#include "../inc/Account.hpp"
#include <iostream>

int main()
{
	std::cout << "=== CREATING BANK ===" << std::endl;
	Bank bank = Bank();

	std::cout << "\n=== CREATING ACCOUNTS ===" << std::endl;
	Account* accountA = bank.createAccount();
	bank.createAccount();

	std::cout << "\n=== INITIAL STATE ===" << std::endl;
	std::cout << bank << std::endl;

	std::cout << "=== DEPOSITS ===" << std::endl;
	// Bank receives 5% of each deposit
	bank.deposit(0, 100);  // Account A gets 95, bank gets 5
	bank.deposit(1, 100);  // Account B gets 95, bank gets 5

	std::cout << "\n=== AFTER DEPOSITS ===" << std::endl;
	std::cout << bank << std::endl;

	std::cout << "=== GIVING LOAN ===" << std::endl;
	// Bank can give loan within its liquidity (10)
	bank.giveLoan(0, 5);  // Should work (bank has 10 liquidity)

	std::cout << "\n=== AFTER LOAN ===" << std::endl;
	std::cout << bank << std::endl;

	std::cout << "=== TRYING INVALID LOAN ===" << std::endl;
	// This should fail - bank doesn't have enough liquidity
	bank.giveLoan(1, 100);

	std::cout << "\n=== WITHDRAWAL ===" << std::endl;
	bank.withdraw(0, 50);  // Should work

	std::cout << "\n=== TRYING INVALID WITHDRAWAL ===" << std::endl;
	bank.withdraw(1, 200);  // Should fail - insufficient funds

	std::cout << "\n=== FINAL STATE ===" << std::endl;
	std::cout << bank << std::endl;

	std::cout << "=== DELETING ACCOUNT ===" << std::endl;
	bank.deleteAccount(1);

	std::cout << "\n=== AFTER DELETION ===" << std::endl;
	std::cout << bank << std::endl;

	std::cout << "=== TESTING ENCAPSULATION ===" << std::endl;
	std::cout << "Account A ID: " << accountA->getId() << std::endl;
	std::cout << "Account A Value: " << accountA->getValue() << std::endl;
	std::cout << "Bank Liquidity: " << bank.getLiquidity() << std::endl;
	
	// These lines would NOT compile (proving encapsulation works):
	// accountA->_id = 999;        // ERROR: _id is private
	// accountA->_value = 999999;  // ERROR: _value is private
	// bank._liquidity = 999999;   // ERROR: _liquidity is private

	std::cout << "\n=== END ===" << std::endl;
	return 0;
}
