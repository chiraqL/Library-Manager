#pragma once
#include <string>

const int MAX_BOOKS_ISSUED = 5;
const int MAX_DUE_DAY = 30;

class Book
{
public:
	enum Category :unsigned char
	{
		Science = 0,
		Fiction,
		Computer,
		Literature,
		Children,
		History,
		Biography
	};
	Book();
	std::string getTitle();
	bool getStatus();
	bool checkOut();
	~Book();

private:
	char isbn[13];
	std::string title;
	std::string author;
	Category category;
	bool is_available;
	int shelf_num;
	int shelf_row;
	int shelf_col;
	int pages;

	friend class System;
};

struct Date
{
	int day, month, year;
};
struct Book_Issued
{
	Book book;
	Date issue_date;
	Date due_date;	
};