#include "Headers.h"
fstream fp, fp1, fp2;
student stud;
book bk;
graphics gp;
tools j;
book itemb[MAX];
student items[MAX];
AlgorithmBook abook;
AlgorithmStudent astud;
void file::add_new_book() {
	fp.open("book.txt", ios::out | ios::app);
	system("CLS");
	gp.stdbox();
	system("CLS");
	gp.stdbox();
	bk.add_book();
	fp.write(reinterpret_cast<char*>(&bk), sizeof(book));
	fp.close();
	_getch();
}

void file::add_new_std() {
	fp.open("student.txt", ios::out | ios::app);
	system("CLS");
	gp.stdbox();
	stud.add_student();
	fp.write(reinterpret_cast<char*>(&stud), sizeof(student));
	fp.close();
	_getch();
}

void file::list_book_table() {
	system("CLS");
	fp.open("book.txt", ios::in);
	if (!fp) {
		cout << "File not found" << endl;
		return;
	}
	cout << "\t\t\tBOOK LIST\n\n\n" << endl;


	cout << "\t" << "Book no" << setw(24) << "Name" << setw(24) << "Author" << setw(24) << "Quantity" << setw(24) << "price";
	while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book))) {
		cout << endl;
		bk.blist();
	}

	gp.tablebook();
	fp.close();
	_getch();
}

void file::list_std_table() {
	system("cls");
	fp.open("student.txt", ios::in);
	if (!fp) {
		cout << "File not found" << endl;
		return;
	}
	cout << "\t\tSTUDENT LIST\n\n";
	cout << "\n\n";
	cout << " \t" << "Roll no" << setw(40) << " Name" << setw(40) << " issued ";
	while (fp.read(reinterpret_cast<char*>(&stud), sizeof(student))) {
		stud.slist();
	}
	gp.tablestd();
	fp.close();
	_getch();
}
void file::search_book() {
	gp.stdbox();
	j.setxy(47, 6);
	cout << "BOOK INFORMATION" << endl;
	j.setxy(47, 8);
	cout << "Enter book  number";
	j.setxy(47, 9);
	cin >> x;
	int f = 0;
	system("CLS");
	gp.stdbox();
	fp.open("book.txt", ios::in);
	while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book))) {
		if (_strcmpi(bk.returnbook_no(), x) == 0) {

			bk.display_book();
			gp.miscbox();
			f = 1;
		}

	}
	fp.close();
	if (f == 0) {
		cout << "No any record found" << endl;
	}
	_getch();
}
void file::search_std() {

	

	
	
}

void file::modify_book() {
	int f = 0;
	gp.stdbox();
	j.setxy(47, 6);
	cout << "MODIFY BOOK" << endl;
	j.setxy(47, 8);
	cout << "Enter the Book number" << endl;
	j.setxy(47, 9);
	cin >> x;
	system("CLS");
	gp.stdbox();
	fp.open("book.txt", ios::in | ios::out);
	while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book))) {
		if (_strcmpi(bk.returnbook_no(), x) == 0) {
			bk.display_book();
			j.setxy(47, 19);
			cout << "Enter new details " << endl;
			_getch();
			system("CLS");
			gp.stdbox();
			bk.modifybook();
			int pos = (-1) * sizeof(bk);
			fp.seekp(pos, ios::cur);
			fp.write(reinterpret_cast<char*>(&bk), sizeof(book));
			j.setxy(47, 19);
			cout << "new details updated" << endl;
			f = 1;
			break;
		}
	}
	fp.close();
	if (f == 0)
		cout << " No Record Found ";
	_getch();

}
void file::modify_std() {
	int f = 0;
	gp.stdbox();
	j.setxy(47, 6);
	cout << "MODIFY STUDENT" << endl;
	j.setxy(47, 8);
	cout << "Enter Roll number" << endl;
	char x[20];
	j.setxy(47, 9);
	cin >> x;
	system("cls");
	gp.stdbox();
	fp.open("student.txt", ios::in | ios::out);
	while (fp.read(reinterpret_cast<char*>(&stud), sizeof(student))) {
		if (_strcmpi(stud.returnstudent_roll(), x) == 0) {
			system("cls");
			stud.display_student_sts(6);
			j.setxy(47, 19);
			cout << "Enter new details" << endl;
			_getch();
			system("CLS");
			gp.stdbox();
			stud.modify_student();
			int pos = (-1) * sizeof(stud);
			fp.seekp(pos, ios::cur);
			fp.write(reinterpret_cast<char*>(&stud), sizeof(student));
			j.setxy(47, 19);
			cout << "new details updated" << endl;
			f = 1;
			break;
		}
	}
	fp.close();
	if (f == 0) {
		cout << "No record found" << endl;
	}
	_getch();
}
void file::delete_std()
{
	system("CLS");
	gp.stdbox();
	int f = 0;
	j.setxy(47, 8);
	cout << "DELETE STUDENT";
	j.setxy(47, 10);
	cout << "Enter Roll number";
	char x[20];
	cin >> x;
	fp.open("student.txt", ios::in | ios::out);
	fp2.open("Temp.txt", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read(reinterpret_cast<char*>(&stud), sizeof(student)))
	{
		if (_strcmpi(stud.returnstudent_roll(), x) != 0)
			fp2.write(reinterpret_cast<char*>(&stud), sizeof(student));
		else
			f = 1;
	}
	fp.close();
	fp2.close();
	remove("student.txt");
	(void)rename("Temp.txt", "student.txt");
	if (f == 1) {
		j.setxy(47, 20);

		cout << "Record deleted";
	}
	else {
		j.setxy(47, 20);
		cout << "Nop record found";
	}
	_getch();
}

void file::delete_book() {
	system("CLS");
	gp.stdbox();
	j.setxy(47, 8);
	cout << "DELETE BOOK";
	j.setxy(47, 10);
	cout << "Enter  Book no: ";
	char x[20];
	j.setxy(47, 11);
	cin >> x;
	fp.open("book.txt", ios::in | ios::out);
	fp2.open("Temp.txt", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book)))
	{
		if (_strcmpi(bk.returnbook_no(), x) != 0)
		{
			fp2.write(reinterpret_cast<char*>(&bk), sizeof(book));
		}
	}
	fp.close();
	fp2.close();
	remove("book.txt");
	(void)rename("Temp.txt", "book.txt");
	j.setxy(47, 20);
	cout << "Record Deleted";
	(void)_getch();
}

void file::issue_book() {
	system("CLS");
	gp.miscbox();
	j.setxy(47, 8);
	cout << "Book issue" << endl;
	j.setxy(47, 10);
	cout << "Enter Roll number" << endl;
	j.setxy(47, 11);
	cin >> roll;
	system("CLS");
	gp.miscbox();
	j.setxy(47, 8);
	cout << "Book issue" << endl;
	j.setxy(47, 10);
	fp.open("student.txt", ios::in | ios::out);
	fp1.open("book.txt", ios::in | ios::out);
	int found = 0;
	int flag = 0;
	while (fp.read((char*)&stud, sizeof(student)) && found == 0) {
		if (_strcmpi(stud.returnstudent_roll(), roll) == 0) {
			found = 1;
			if (stud.returntoken() == 0) {
				j.setxy(47, 12);
				cout << "Enter the book number" << endl;
				j.setxy(47, 14);
				cin >> book_num;
				while (fp1.read(reinterpret_cast<char*>(&bk), sizeof(book)) && flag == 0) {
					if (_strcmpi(bk.returnbook_no(), book_num) == 0) {
						bk.display_book();
						flag = 1;
						stud.addtoken();
						stud.gettokenbookno(bk.returnbook_no());
						int pos = (-1) * sizeof(student);
						fp.seekp(pos, ios::cur);
						fp.write(reinterpret_cast<char*>(&stud), sizeof(student));
						fp.clear();
						fp.seekg(0);
						fp1.clear();
						fp1.seekg(0);

						j.setxy(47, 20);
						cout << "BOOK ISSSUED SUCESSFULLY" << endl;

						break;
					}
				}
				if (flag == 0) {
					j.setxy(47, 20);
					cout << "No book exist" << endl;
				}
			}

		}


	}
	if (found == 0) {
		j.setxy(47, 20);
		cout << "Student record not exist";
	}
	fp.close();
	fp1.close();
	_getch();
}

void file::deposit_book() {
	system("CLS");
	gp.miscbox();
	j.setxy(47, 8);
	cout << "BOOK DEPOSIT" << endl;
	j.setxy(47, 10);
	cout << "Enter student roll  no" << endl;
	j.setxy(47, 11);
	cin >> roll;
	system("CLS");
	gp.miscbox();
	j.setxy(47, 8);
	cout << "BOOK DEPOSIT" << endl;
	j.setxy(47, 10);
	fp.open("student.txt", ios::in | ios::out);
	fp1.open("book.txt", ios::in | ios::out);
	int found = 0;
	int flag = 0;
	while (fp.read(reinterpret_cast<char*>(&stud), sizeof(student)) && found == 0) {
		if (_strcmpi(stud.returnstudent_roll(), roll) == 0) {
			found = 1;
			if (stud.returntoken() == 1) {
				while (fp1.read(reinterpret_cast<char*>(&bk), sizeof(book)) && flag == 0) {
					if (_strcmpi(bk.returnbook_no(), stud.returnbook_issued()) == 0) {
						bk.display_book();
						flag = 1;
						stud.resettoken();
						int pos = -1 * sizeof(stud);
						fp.seekp(pos, ios::cur);
						fp.write(reinterpret_cast<char*>(&stud), sizeof(student));
						fp.clear();
						fp.seekg(0);
						fp1.clear();
						fp1.seekg(0);
						j.setxy(47, 20);
						cout << "book deposited" << endl;
						break;
					}
				}
				if (flag == 0) {
					j.setxy(47, 20);
					cout << "Book doesnot exist" << endl;
				}
			}
		}

	}
	if (found == 0) {
		j.setxy(47, 20);
		cout << "Student record not exist";
	}
	fp.close();
	fp1.close();
	_getch();
}


void file::list_book(int algo, bool order, bool type, int sortby)	
{
	int temp;
	fp.open("book.txt", ios::in | ios::out);
	temp = j.bookcounter();
	for (int i = 0; i < temp; i++) {
		fp.read(reinterpret_cast<char*>(&bk), sizeof(book));
		itemb[i] = bk;
	}

	int time_taken;
	system("CLS");
	switch (algo)
	{
	case 1:
		j.setxy(55, 1);
		cout << "Bubble sort";
		time_taken = abook.list_book_bubblesort(itemb, temp, order, type, sortby);

		break;
	case 2:
		j.setxy(55, 1);
		cout << "Selection Sort";
		time_taken = abook.list_book_selectionsort(itemb, temp, order, type, sortby);
		break;
	case 3:
		j.setxy(55, 1);
		cout << "Insertion sort";
		time_taken = abook.list_book_insertionsort(itemb, temp, order, type, sortby);
		break;
	case 4:
		j.setxy(55, 1);
		cout << "Merge sort";
		time_taken = abook.list_book_mergesort(itemb, temp, order, type, sortby);
		break;
	case 5:
		j.setxy(55, 1);
		cout << "Heap sort";
		time_taken = abook.list_book_heapsort(itemb, temp, order, type, sortby);
		break;
	case 6:
		j.setxy(55, 1);
		cout << "Quick sort";
		time_taken = abook.list_book_quicksort(itemb, temp, order, type, sortby);
		break;
	case 7:
		j.setxy(55, 1);
		cout << "Bogo sort";
		time_taken = abook.list_book_bogosort(itemb, temp, order, type, sortby);
		break;
	default:
		break;
	}
	cout << "\n\n\n";
	cout << "\t" << "Book no" << setw(24) << "Name" << setw(24) << "Author" << setw(24) << "Quantity" << setw(24) << "price";
	for (int i = 0; i < temp; i++)
		itemb[i].blist();
	j.setxy(90, 2);
	cout << fixed;
	std::cout << "Time taken::" << (float)time_taken * 10e-9 << setw(2) << " seconds" << std::endl;
	gp.tablebook();
	_getch();
	fp.close();
}

void file::list_student(int algo, bool order, bool type, int sortby)
{
	int temp;
	fp.open("student.txt", ios::in | ios::out);
	temp = j.studentcounter();
	for (int i = 0; i < temp; i++) {
		fp.read(reinterpret_cast<char*>(&stud), sizeof(student));
		items[i] = stud;
	}

	int time_taken;
	system("CLS");
	switch (algo)
	{
	case 1:
		j.setxy(55, 1);
		cout << "Bubble sort";
		time_taken = astud.list_student_bubblesort(items, temp, order, type, sortby);

		break;
	case 2:
		j.setxy(55, 1);
		cout << "Selection Sort";
		time_taken = astud.list_student_selectionsort(items, temp, order, type, sortby);
		break;
	case 3:
		j.setxy(55, 1);
		cout << "Insertion sort";
		time_taken = astud.list_student_insertionsort(items, temp, order, type, sortby);
		break;
	case 4:
		j.setxy(55, 1);
		cout << "Merge sort";
		time_taken = astud.list_student_mergesort(items, temp, order, type, sortby);
		break;
	case 5:
		j.setxy(55, 1);
		cout << "Heap sort";
		time_taken = astud.list_student_heapsort(items, temp, order, type, sortby);
		break;
	case 6:
		j.setxy(55, 1);
		cout << "Quick sort";
		time_taken = astud.list_student_quicksort(items, temp, order, type, sortby);
		break;
	case 7:
		j.setxy(55, 1);
		cout << "Bogo sort";
		time_taken = astud.list_student_bogosort(items, temp, order, type, sortby);
		break;
	default:
		break;
	}
	cout << "\n\n\n";
	cout << "\t" << "Roll no." << setw(24) << "Name" << setw(24) << "# of Books Issued" << setw(24) << "Quantity" << setw(24) << "price";
	for (int i = 0; i < temp; i++)
		items[i].slist();
	j.setxy(90, 2);
	cout << fixed;
	std::cout << "Time taken::" << (float)time_taken * 10e-9 << setw(2) << " seconds" << std::endl;
	gp.tablebook();
	_getch();
	fp.close();
}

void file::binarysearch_book() {

	gp.miscbox();
	j.setxy(47, 6);
	cin.ignore();
	cout << "BOOK INFORMATION" << endl;
	j.setxy(47, 8);
	cout << "Enter book  name";
	j.setxy(47, 9);
	cin.getline(x, 50);
	int f = 0;
	system("CLS");
	gp.miscbox();
	fp.open("book.txt", ios::in | ios::out);
	int temp = j.bookcounter();
	for (int i = 0; i <= temp; i++) {
		fp.read(reinterpret_cast<char*>(&bk), sizeof(book));
		itemb[i] = bk;
	}
	f = abook.binary_search_book(itemb, 0, temp, x);
	if (strcmp(itemb[f].book_name, x) == 0) {
		f = 1;
		itemb[f].display_book();
	}
	fp.close();
	if (f == 0) {
		cout << "No any record found" << endl;
	}
	_getch();
}

void file::search_student(int searchby)
{
	cin.ignore();
	if (searchby == 1)
		cout << "Enter student name::";
	else if(searchby==2)
		cout << "Enter Roll no.";
	cin.getline(x, 50);
	int f = 0;
	system("CLS");
	gp.stdbox();
	int temp = j.studentcounter();
	student studsearchlist[50];
	fp.open("student.txt", ios::in);
	for (int i = 0; i < temp; i++) {
		fp.read(reinterpret_cast<char*>(&stud), sizeof(student));
		items[i] = stud;
	}
	fp.close();
	int ret = astud.linear_search_student(items,temp, x,searchby);
	if (ret == 1)
		cout << "Record not found";
	_getch();
}

