#pragma once
#include "Headers.h"
class book {
public:
	
	char authorname[30];
	char publication_name[30];
	char book_no[30];
	int quantity;
	int n;
public:
	int price;
	char book_name[30];
	void display_book();
	void add_book();
	void modifybook();
	void blist();
	char* returnbook_no();
	char *returnbook_name();

	void copy_book(book&);
};