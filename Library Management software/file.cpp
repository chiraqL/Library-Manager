#include "Headers.h"
fstream fp, fp1, fp2;
student stud;
book bk;
graphics gp;
tools j;
book itemb[MAX];
student items[MAX];
algorithm al;
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

	
	cout << "\t"<<"Book no" << setw(24) << "Name" << setw(24) << "Author" << setw(24) << "Quantity" << setw(24) << "price";
	while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book))) {
		cout << endl;
		bk.blist();
	}
	
	gp.tablebook();
	fp.close();
	_getch();
}

void file::list_std_table(){
	system("cls");
	fp.open("student.txt", ios::in);
	if (!fp) {
		cout << "File not found" << endl;
		return;
	}
	cout << "\t\tSTUDENT LIST\n\n";
	cout << "\n\n";
	cout <<" \t"<<"Roll no"<<setw(40)<<" Name"<< setw(40)<<" issued " ;
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
	gp.stdbox();
	j.setxy(47, 6);
	cout << "STUDENT INFORMATION" << endl;
	j.setxy(47, 8);
	cout << "Enter student roll  number";
	j.setxy(47, 9);
	cin >> x;
	int f = 0;
	system("CLS");
	gp.stdbox();
	fp.open("student.txt", ios::in );
	while (fp.read(reinterpret_cast<char*>(&stud), sizeof(student)))
	{
		if (_strcmpi(stud.returnstudent_roll(), x) == 0) {
			stud.display_student_sts();
			f = 1;
		}
	}
	fp.close();
	if (f== 0) {
		cout << "No any record found" << endl;
	}
	_getch();
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
	fp.open("book.txt", ios::in |ios::out);
	while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book))) {
		if (_strcmpi(bk.returnbook_no(), x) == 0) {
			bk.display_book();
			cout << "Enter the new details of book" << endl;
			bk.modifybook();
			int pos = (-1 )* sizeof(bk);
			fp.seekp(pos, ios::cur);
			fp.write(reinterpret_cast<char*>(&bk), sizeof(book));
			cout << "new details has been updated" << endl;
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
	fp.open("student.txt", ios::in | ios::out );
	while (fp.read(reinterpret_cast<char*>(&stud), sizeof(student))) {
		if (_strcmpi(stud.returnstudent_roll(), x) == 0) {
			stud.display_student_sts();
			cout << "Enter the new detsils of students::" << endl;
			stud.modify_student();
			int pos = (-1 )* sizeof(stud);
			fp.seekp(pos, ios::cur);
			fp.write(reinterpret_cast<char*>(&stud), sizeof(student));
			cout << "new details has been updated" << endl;
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
		(void )rename("Temp.txt", "student.txt");
		if (f == 1) {
			j.setxy(47, 20);

			cout << "Record has been deleted";
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
cout << "Record Deleted has been deleted";
(void)_getch();
}

void file::issue_book() {
	system("CLS");
	gp.stdbox();
	j.setxy(47, 8);
	cout << "Book issue" << endl;
	j.setxy(47, 10);
	cout << "Enter Roll number" << endl;
	j.setxy(47, 11);
	cin >> roll;
	fp.open("student.txt", ios::in | ios::out);
	fp1.open("book.txt", ios::in | ios::out);
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
				/*else {
					j.setxy(47, 20);
					cout << "Not returned book" << endl;
				}*/
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
	gp.stdbox();
	j.setxy(47, 8);
	cout << "BOOK DEPOSIT" << endl;
	j.setxy(47, 10);
	cout << "Enter student roll  no" << endl;
	j.setxy(47, 11);
	cin >> roll;
	fp.open("student.txt", ios::in | ios::out);
	fp1.open("book.txt", ios::in | ios::out);
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
				/*else {
					j.setxy(47, 20);
					cout << "No book issued" << endl;
				}*/
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
	fp.open("book.txt", ios::in | ios::out);
	int temp = j.bookcounter();
	for (int i = 0; i < temp; i++) {
		fp.read(reinterpret_cast<char*>(&bk), sizeof(book));
		itemb[i] = bk;
	}
	int time_taken;
	system("CLS");
	switch (algo)
	{
	case 1:
		time_taken = al.list_book_bubblesort(itemb, temp, order, type, sortby);
		break;
	case 2:
		time_taken = al.list_book_selectionsort(itemb, temp,order, type, sortby);
		break;
	case 3:
		time_taken = al.list_book_insertionsort(itemb, temp,order, type, sortby);
		break;
	case 4:
		time_taken = al.list_book_mergesort(itemb, temp, order, type, sortby);
		break;
	case 5:
		time_taken = al.list_book_heapsort(itemb, temp,order, type, sortby);
		break;
	case 6:
		time_taken = al.list_book_quicksort(itemb, temp,order, type, sortby);
		break;
	case 7:
		time_taken = al.list_book_bogosort(itemb, temp,order, type, sortby);
		break;
	default:
		break;
	}
	for (int i = 0; i < temp; i++)
		itemb[i].blist();
	std::cout << "\nTime taken::" << time_taken << std::endl;
	_getch();
	fp.close();
}

void file::binarysearch_book() {
	gp.stdbox();
	j.setxy(47, 6);
	cin.ignore();
	cout << "BOOK INFORMATION" << endl;
	j.setxy(47, 8);
	cout << "Enter book  name";
	j.setxy(47, 9);
	cin.getline(x, 50);
	int f = 0;
	system("CLS");
	gp.stdbox();
	fp.open("book.txt", ios::in|ios::out);
	int temp = j.bookcounter();
	for (int i = 0; i <= temp; i++) {
		fp.read(reinterpret_cast<char*>(&bk), sizeof(book));
		itemb[i] = bk;
	}
	f=al.binary_search_book(itemb, 0, temp, x);
	if (strcmp(itemb[f].book_name, x) == 0) {
		itemb[f].display_book();
	}
	fp.close();
	if (f == 0) {
		cout << "No any record found" << endl;
	}
	_getch();
}

