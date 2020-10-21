#pragma once
#include <string>

class Account
{
public:
	Account() {};
	~Account() {};

private:
	std::string id;
	std::string user_name;
	std::string pass;
};
