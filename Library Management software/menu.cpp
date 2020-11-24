#include "Headers.h"

file f1;
adminpassword a;
librarianpassword lp;
login l;
graphics gra;
tools to;
Sortmenu sort_menu;
Searchmenu search_menu;

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
		sort_menu.sort_book_menu();
		bool type = (sort_menu.sortby == 1 || sort_menu.sortby == 4) ? 1 : 0;				//0 for string; 1 for int
		if ((sort_menu.order == 0 || sort_menu.order == 1) && (sort_menu.sorting_algo >= 1 && sort_menu.sorting_algo <= 7) && (sort_menu.sortby >= 1 && sort_menu.sortby <= 5))
			f1.list_book(sort_menu.sorting_algo, sort_menu.order, type, sort_menu.sortby);
		else
			std::cout << "Invalid Selection!";
		break;
	}
	case 2: {
		search_menu.search_book_menu();
		if ((search_menu.searchby == 1 || search_menu.searchby == 2) && ((search_menu.searching_algo == 1 || search_menu.searching_algo == 2)))
			f1.search_book(search_menu.searching_algo, 0, 0, search_menu.searchby);				//0 for ascending; 0 for string; 
		else
			cout << "error";
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
	cout << "8.Search book" << endl;
	to.setxy(47, 13);
	cout << "9.Sort book" << endl;
	to.setxy(47, 14);
	cout << "10.Sort Student" << endl;
	to.setxy(47, 15);
	cout << "11.List student" << endl;
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
		search_menu.search_student_menu();
		if (search_menu.searchby <= 2)
			f1.search_student(search_menu.searching_algo, 0, 0, search_menu.searchby);			//0 for ascending; 0 for string;
		else
			cout << "Error";
		break;
	}
	case 8:
	{
		search_menu.search_book_menu();
		if (search_menu.searchby <= 2)
			f1.search_book(search_menu.searching_algo, 0, 0, search_menu.searchby);				//0 for ascending; 0 for string;
		else
			cout << "Error";
		break;
	}
	case 9:
	{
		sort_menu.sort_book_menu();
		bool type = (sort_menu.sortby == 1 || sort_menu.sortby == 4) ? 1 : 0;				//0 for string; 1 for int
		if (sort_menu.order <= 1 && sort_menu.sorting_algo < 8 && sort_menu.sortby>0)
			f1.list_book(sort_menu.sorting_algo, sort_menu.order, type, sort_menu.sortby);
		else
			std::cout << "Error";
		break;
	}
	case 10:
	{
		sort_menu.sort_student_menu();
		bool type = (sort_menu.sortby == 3) ? 1 : 0;										//0 for string; 1 for int
		if (sort_menu.order <= 1 && sort_menu.sorting_algo < 8 && sort_menu.sortby>0)
			f1.list_student(sort_menu.sorting_algo, sort_menu.order, type, sort_menu.sortby);
		else
			std::cout << "Error";
		break;
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
		system("CLS");
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
	cout << "3.Go to login" << endl;
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
	system("CLS");
	librarianmenu a;
	a.menu();
	}
}