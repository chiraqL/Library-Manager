#include "Headers.h"
tools f;
void student::add_student() {
	
	f.setxy(47, 6);
	cout << "Create new student" << setw(2) << endl;
	f.setxy(47, 7);
	cout << "Enter Roll number" << setw(2) << endl;
	f.setxy(47, 8);
	cin >> roll;
	cin.ignore();
	f.setxy(47, 9);
	cout << "Enter student Name:" << setw(2) << endl;
	f.setxy(47, 10);
	cin.getline(std_name, 50);
	book_issued[0] = NULL;
	token = 0;
	f.setxy(47, 19);
	cout << "New student created" << setw(2) << endl;
}

void student::display_student_sts() {
	system("CLS");
	f.setxy(47, 6);
	cout << " roll no: " << setw(2) << roll << setw(2) << endl;
	f.setxy(47, 8);
	cout << "Student Name: " << setw(2) << std_name << setw(2) << endl;
	f.setxy(47, 10);
	cout << "Number of book issued" << setw(2) << setw(2) << token;
	if (token == 1)
	{
		f.setxy(47, 12);
		cout << " Book Number " << setw(2) << book_issued;
	}
}

void student::modify_student() {
	system("CLS");
	f.setxy(47, 6);
	cout << " Roll no: " << roll << setw(2) << endl;
	f.setxy(47, 8);
	cout << "Modify Student Name: " << setw(2) << endl;
	f.setxy(47, 9);
	cin >> std_name;
}

void student::slist() {
	cout << endl;
	cout  <<"\t"<< roll << setw(40) << std_name << setw(40) << token;
}
char* student::returnstudent_roll(){
	return roll;
}
int student::returntoken() {
	return token;
}

void student::addtoken() {
	token = 1;
}
void student::gettokenbookno(char t[]) {

	strcpy_s(book_issued, t);
}
	
char* student::returnbook_issued() {
	return book_issued;
}

void student::resettoken() {
	token = 0;
}

