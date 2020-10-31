#pragma once
#include"allheader.h"
class book {
public:
	
	char authorname[50];
	char publication_name[50];
	char  book_no[20];
	int quantity;
	int n;
public:
	float price;
	char book_name[50];
	void display_book();
	void add_book();
	void modifybook();
	void blist();
	char* returnbook_no();
	char *returnbook_name();

	void copy_book(book&);
};