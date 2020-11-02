#pragma once
#include "Headers.h"
class file {
private:
	char roll[50];
	char book_num[50];
	char x[50];
	int count=0;
	int LB = 0;
	int mid;
	int n;
public:

	void add_new_book();
	void add_new_std();
	void list_book_table();
	void list_std_table();
	void search_std();
	void search_book();
	void modify_book();
	void modify_std();
	void delete_std();
	void delete_book();
	void sort_std();

	void list_book(int, bool, bool, int);
	void list_student(int, bool, bool, int);

	void issue_book();
	void deposit_book();
	void binarysearch_book();//remove binary from name
	void search_student(int );
	
};
