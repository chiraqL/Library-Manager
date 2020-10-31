#pragma once
#include"allheader.h"
class student {
private:
	char std_name[20];
	int token;
	char book_issued[20];
	char roll[20];
public:
	void add_student();
	void display_student_sts();
	void slist();
	void modify_student();
	char* returnstudent_roll();
	int  returntoken();
	void addtoken();
	void gettokenbookno(char t[]);
	char* returnbook_issued();
	void resettoken();

};