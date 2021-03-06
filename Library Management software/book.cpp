#include "Headers.h"
tools u;
void book::display_book() {

	u.setxy(47, 6);
	cout << "Book number:" << " " << book_no << endl;
	u.setxy(47, 8);
	cout << "Name:" << " " << book_name << endl;
	u.setxy(47, 10);
	cout << "Author Name:" << " " << authorname << endl;
	u.setxy(47, 12);
	cout << "Publication:" << " " << publication_name << endl;
	u.setxy(47, 14);
	cout << "Quantity:" << " " << quantity << endl;
	u.setxy(47, 16);
	cout << "Price:" << " " << price << endl;

}



void book::add_book() {

	u.setxy(47, 5);
	cout << "Enter Book number:" << setw(2) << endl;
	u.setxy(47, 6);
	cin >> book_no;
	cin.ignore();
	u.setxy(47, 7);
	cout << "Enter Book's Name: " << setw(2) << endl;
	u.setxy(47, 8);
	cin.getline(book_name, 50);
	u.setxy(47, 9);
	cout << "Enter Author's Name:" << setw(2) << endl;
	u.setxy(47, 10);
	cin.getline(authorname, 50);
	u.setxy(47, 11);
	cout << "Enter Publication Name:" << setw(2) << endl;
	u.setxy(47, 12);
	cin.getline(publication_name, 50);
	u.setxy(47, 13);
	cout << "Enter Book's quantity:" << setw(2) << endl;
	u.setxy(47, 14);
	cin >> quantity;
	u.setxy(47, 15);
	cout << "Enter book price:" << setw(2) << endl;
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
	cout << endl;
	cout << "  " << book_no << setw(32) << book_name << setw(26) << authorname << setw(20) << quantity << setw(24) << price;
}
char* book::returnbook_no() {
	return book_no;
}
char* book::returnbook_name() {
	return book_name;
}

void book::copy_book(book& T)
{
	strncpy_s(T.book_no, this->book_no, _TRUNCATE);
	strncpy_s(T.book_name, this->book_name, _TRUNCATE);
	strncpy_s(T.authorname, this->authorname, _TRUNCATE);
	strncpy_s(T.publication_name, this->publication_name, _TRUNCATE);
	T.quantity = this->quantity;
	T.price = this->price;
}
