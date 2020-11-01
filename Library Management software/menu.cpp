#include "Headers.h"
file f1;
adminpassword a;
librarianpassword lp;
login l;
graphics gra;
tools to;
void studentmenu::menu() {
	gra.stdbox();
	to.setxy(47, 5);
	cout << "Student Menu";
	to.setxy(47, 6);
	cout << "1.Book list" << endl;
	to.setxy(47, 7);
	cout << "2.Search Book" << endl;
	to.setxy(47, 8);
	cout << "3.Go back to menu" << endl;
	to.setxy(47, 19);
	cout << "Choose option" << endl;
	to.setxy(47, 20);
	cin >> n;
	switch (n) {
	case 1: {
		system("CLS");
		gra.stdbox();
		to.setxy(47, 5);
		cout << "Sort By:";
		to.setxy(47, 6);
		cout << "1.Price";
		to.setxy(47, 7);
		cout << "2.Book Name";
		to.setxy(47, 8);
		cout << "3.Author Name";
		to.setxy(47, 9);
		cout << "4.Quantity";
		to.setxy(47, 10);
		cout << "5.Publisher";
		to.setxy(47, 19);
		cout << "Choose option" << endl;
		
		int sortby;
		to.setxy(47, 20);
		cin >> sortby;

		system("CLS");
		gra.passwordbox();
		to.setxy(47, 8);
		cout << "0.Ascending Order";
		to.setxy(47, 9);
		cout << "1.Decending Order";
		to.setxy(47, 10);
		int order;
		cin >> order;

		system("CLS");
		gra.stdbox();
		to.setxy(47, 5);
		cout << "Select The type of sort";
		to.setxy(47, 6);
		cout << "1.Bubble Sort";
		to.setxy(47, 7);
		cout << "2.Selection Sort";
		to.setxy(47, 8);
		cout << "3.Insertion Sort";
		to.setxy(47, 9);
		cout << "4.Merge Sort";
		to.setxy(47, 10);
		cout << "5.Heap Sort";
		to.setxy(47, 11);
		cout << "6.Quick sort";
		to.setxy(47, 12);
		cout << "7.Bogo Sort";
		to.setxy(47, 19);
		cout << "Choose option" << endl;
		int sorting_algo;
		to.setxy(47, 20);
		cin >> sorting_algo;

		bool type = (sortby == 1 || sortby == 4) ? 1 : 0;
		if (order <= 1 && sorting_algo < 8 && sortby>0)
			f1.list_book(sorting_algo, order, type, sortby);//0 for string;1 for sortby
		else
			std::cout << "Error";
		break;
	}
	case 2: {
		system("CLS");
		f1.binarysearch_book();
		break;
	}
	case 3: {
		system("CLS");
		l.loginscreen();
		break;
	}
	default: {
		cout << "Incorrect selection" << endl;
	}
	}
	system("CLS");
	studentmenu a;
	a.menu();
}
void adminmenu::menu() {
	
	system("CLS");
	to.setxy(47, 4);
	cout << "ADMINISTRATOR MENU";
	gra.adminbox();
	to.setxy(47, 5);
	cout << "1.Add student" << endl;
	to.setxy(47, 6);
	cout << "2.Add Book" << endl;
	to.setxy(47, 7);
	cout << "3.Delete student" << endl;
	to.setxy(47, 8);
	cout << "4.Delete Book" << endl;
	to.setxy(47, 9);
	cout << "5.Modify Student" << endl;
	to.setxy(47, 10);
	cout << "6.Modify Book" << endl;
	to.setxy(47, 11);
	cout << "7.Search Student" << endl;
	to.setxy(47, 12);
	cout << "8.search book" << endl;
	to.setxy(47, 13);
	cout << "9.Sort book" << endl;
	to.setxy(47, 14);
	cout << "10.Sort Student" << endl;
	to.setxy(47, 15);
	cout<<"11.List student" <<endl;
	to.setxy(47, 16);
	cout << "12.List book" << endl;
	to.setxy(47, 17);
	cout << "13.Reset admin password" << endl;
	to.setxy(47, 18);
	cout << "14.Reset librarian password" << endl;
	to.setxy(47, 19);
	cout << "15.Go to login menu" << endl;
	to.setxy(47, 23);
	cout << "choose option" << endl;
	to.setxy(47, 24);
	cin >> n;
	switch (n) {
	case 1: {
		system("CLS");
		f1.add_new_std();
		break;
	}
	case 2:
	{
		system("CLS");
		f1.add_new_book();
		break;
	}
	case 3:
	{
		system("CLS");
		f1.delete_std();
		break;

	}
	case 4: {
		system("CLS");
		f1.delete_book();
		break;
	}
	case 5:
	{
		system("CLS");
		f1.modify_std();
		break;
	}
	case 6:
	{
		system("CLS");
		f1.modify_book();
		break;
	}
	case 7:
	{
		system("CLS");
		
		f1.search_std();
		break;
	}
	case 8:
	{
		system("CLS");
		
		f1.search_book();
		break;
	}
	case 9:
	{
		system("CLS");
		//f1.sort_book();
	}
	case 10:
	{
		system("CLS");
		//f1.sort_std();
	}
	case 11:
	{
		system("CLS");
		f1.list_std_table();
		break;
	}
	case 12:
	{
		system("CLS");
		f1.list_book_table();
		break;
	}
	case 13:
	{
		system("cls");
		a.reset_pass();
		break;
	}
	case 14:
	{
		system("CLS");
		lp.reset_pass();
		break;
	}
	case 15:
	{
		system("CLS");
		l.loginscreen();
		break;
	}
	default: {
		cout << "Choose correct option" << endl;
	}
	}
	system("CLS");
	adminmenu a;
	a.menu();
}
void librarianmenu::menu()
{
	system("CLS");
	to.setxy(47, 5);
	cout << "LIBRARIAN MENU";
	gra.stdbox();
	to.setxy(47, 7);
	cout << "1.Issue Book" << endl;
	to.setxy(47, 8);
	cout << "2.Deposit Book" << endl;
	to.setxy(47, 9);
	cout << "3.go to login" << endl;
	to.setxy(47, 19);
	cout << "Choose option" << endl;
	to.setxy(47, 20);
	cin >> n;
	switch (n) {
	case 1:
	{
		system("CLS");
		f1.issue_book();
		break;
	}
	case 2:
	{
		system("CLS");
		f1.deposit_book();
		break;
	}
	case 3:
	{
		system("CLS");
		l.loginscreen();
		break;
	}
	default:
	{
		cout << "Choose correct option" << endl;
	}
	}
	system("CLS");
	librarianmenu a;
	a.menu();
 }