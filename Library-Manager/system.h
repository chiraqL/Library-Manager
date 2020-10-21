#pragma once
#include <string>
#include "account.h"
#include "member.h"

class System:Account
{
public:
	System();
	void addBook(char* isbn, std::string title, std::string author, std::string category, int pages);
	void newMember(std::string id, std::string pass, std::string username);
	void checkOut(Book book, Member id);
	void renewBook(Book book, Member id);
	void returnBook(Book book, Member id);
	~System();
private:
};

