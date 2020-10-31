#include "Headers.h"
tools u;
void book::display_book() {
	u.setxy(47, 6);
	cout << "Book number" <<setw(2)<< book_no << endl;
	u.setxy(47, 8);
	cout << "Name" <<  setw(2)<<book_name  << endl;
	u.setxy(47, 10);
	cout << "Author Name " << setw(2) << authorname  << endl;
	u.setxy(47, 12);
	cout << "Publication" << setw(2) << publication_name << setw(2) << endl;
	u.setxy(47, 14);
	cout << "Quantity " << setw(2) << quantity << setw(2) << endl;
	u.setxy(47, 16);
	cout << "Price" << setw(2) << price << setw(2) << endl;
}

void book::add_book() {
	
		u.setxy(47, 5);
		cout << "Enter Book number" << setw(2) << endl;
		u.setxy(47, 6);
		cin >> book_no;
		cin.ignore();
		u.setxy(47, 7);
		cout << "Enter Book's Name: " << setw(2) << endl;
		u.setxy(47, 8);
		//cin >> book_name;
		cin.getline(book_name, 50);
		u.setxy(47, 9);
		cout << "Enter Author's Name:" << setw(2) << endl;
		u.setxy(47, 10);
		cin.getline(authorname, 50);
		//cin >> authorname;
		u.setxy(47, 11);
		cout << "Enter Publication Name:" << setw(2) << endl;
		u.setxy(47, 12);
		cin.getline(publication_name, 50);
		//cin >> publication_name;
		u.setxy(47, 13);
		cout << "Enter Book's quantity:" << setw(2) << endl;
		u.setxy(47, 14);
		cin >>  quantity;
		u.setxy(47, 15);
		cout << "Enter book price" << setw(2) << endl;
		u.setxy(47, 16);
		cin >> price;
		u.setxy(47, 19); 
		cout << "Book has been added!!" << setw(2) << endl;
}

void book::modifybook() {
	u.setxy(47, 6);
	cout << "Modify Book's Name: " << setw(2) << endl;
		u.setxy(47, 8);
	cin >> book_name;
	u.setxy(47, 10);
	cout << "Modify Author's Name:" << setw(2) << endl;
	u.setxy(47, 12);
	cin >> authorname;
	u.setxy(47, 14);
	cout << "Modify Publication Name:" << setw(2) << endl;
	u.setxy(47, 16);
	cin >> publication_name;
}

void book::blist() {
	cout << endl;
	cout  <<setw(4)<< book_no << setw(28) << book_name << setw(28) << authorname << setw(28) << quantity << setw(28) << price;
}
char* book::returnbook_no() {
	return book_no;
}
char* book::returnbook_name() {
	return book_name;
 }

void book::copy_book(book &T)
{
	strncpy_s(T.book_no, this->book_no, _TRUNCATE);
	strncpy_s(T.book_name, this->book_name, _TRUNCATE);
	strncpy_s(T.authorname, this->authorname, _TRUNCATE);
	strncpy_s(T.publication_name, this->publication_name, _TRUNCATE);
	T.quantity = this->quantity;
	T.price = this->price;
}
