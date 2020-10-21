//all books in here
#pragma once
#include <list>

#include "book.h"
#include "system.h"

class Library
{
public:
	Library();
	~Library();

private:
	//pointer to all books
	std::list<Book> libraryBooks;
	friend class System;
};

