#include "../inc/Account.hpp"

// Private constructor - only accessible by Bank (friend class)
Account::Account(int id) : _id(id), _value(0)
{
}

Account::~Account()
{
}

// Const getters - return by reference
const int&	Account::getId() const
{
	return _id;
}

const int&	Account::getValue() const
{
	return _value;
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Account& account)
{
	os << "[" << account._id << "] - [" << account._value << "]";
	return os;
}
