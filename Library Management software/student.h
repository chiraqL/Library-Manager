#pragma once
#include "Headers.h"
class student {
public:
	char std_name[50];
	int token;
	char book_issued[50];
	char roll[50];
public:
	void add_student();
	void display_student_sts(int);
	void slist();
	void modify_student();
	char* returnstudent_roll();
	int  returntoken();
	void addtoken();
	void gettokenbookno(char t[]);
	char* returnbook_issued();
	void resettoken();

	void copy_student(student&);
};