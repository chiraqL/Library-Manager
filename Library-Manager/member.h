#pragma once
#include "book.h"
#include "account.h"
#include <string>
#include <list>

class Member:Account
{
public:
	Member();
	void getUserName();
	void getBorrowedBooks();
	void getNumberOfBooks();
	~Member();

private:
	int total_books_borrowed;
	std::list<Book_Issued> books_borrowed;
};

