#pragma once
#include"allheader.h"
class file {
private:
	char roll[20];
	int found = 0;
	int flag = 0;
	char book_num[20];
	char x[20];
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

	void list_book_asc(int,bool);

	void issue_book();
	void deposit_book();
	void binarysearch_book();
	
};
