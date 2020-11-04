#include "Headers.h"
tools tl;
login lo;
void graphics::stdbox() {

	tl.setxy(45, 3);
	tl.displayhorizontal(30, 219);
	tl.setxy(45, 21);
	tl.displayhorizontal(30, 219);
	tl.displayvertical(45, 3, 21, 219);
	tl.setxy(45, 18);
	tl.displayhorizontal(30, 219);
	tl.displayvertical(74, 3, 21, 219);
}
void graphics::miscbox(){
	tl.setxy(40, 3);
	tl.displayhorizontal(40, 219);
	tl.setxy(40, 21);
	tl.displayhorizontal(40, 219);
	tl.displayvertical(40, 3, 21, 219);
	tl.setxy(40, 18);
	tl.displayhorizontal(40, 219);
	tl.displayvertical(79, 3, 21, 219);


}
void graphics::adminbox() {
	tl.setxy(40, 2);
	tl.displayhorizontal(40, 219);
	tl.setxy(40, 25);
	tl.displayhorizontal(40, 219);
	tl.displayvertical(40, 2, 25, 219);
	tl.setxy(40, 22);
	tl.displayhorizontal(40, 219);
	tl.displayvertical(79, 2, 25, 219);
}
void graphics::header() {
	tl.setxy(56, 1);
	cout << "LIBRARY MANAGEMENT SOFTWARE";
}
void graphics::footer() {

	tl.setxy(47, 27);
	cout << "LIBRARY MANAGEMENT SOFTWARE";
	tl.setxy(40, 28);
	cout  << "Copyright 2020 -- ARPAN | BIBEK | CHIRAG";

}
void graphics::credits() {
	graphics p;
	p.passwordbox();
	tl.setxy(48, 10);
	cout << "E-LIBRARY LMS";
	tl.setxy(48,11);
	cout << "THANK YOU!!";
	tl.setxy(48, 12);
	cout << "ARPAN|BIBEK|CHIRAG";
	_getch();
	system("CLS");
}

void graphics::passwordbox() {
	tl.setxy(45, 7);
	tl.displayhorizontal(30, 219);
	tl.setxy(45, 15);
	tl.displayhorizontal(30, 219);
	tl.displayvertical(45, 7, 15, 219);
	tl.displayvertical(74, 7, 15, 219);

}
void graphics::tablebook() {
	tl.setxy(0, 3);
	tl.displayhorizontal(120, 220);
	tl.setxy(0, 5);
	tl.displayhorizontal(120, 220);
	tl.setxy(0, 29);
	tl.displayhorizontal(120, 220);
	tl.displayvertical(0, 4, 29, 219);
	tl.displayvertical(16, 4, 29, 219);
	tl.displayvertical(48, 4, 29, 219);
	tl.displayvertical(72, 4, 29, 219);
	tl.displayvertical(96, 4, 29, 219);
	tl.displayvertical(118, 4, 29, 219);
	
}

void graphics::tablestd() {
	tl.setxy(0, 3);
	tl.displayhorizontal(120, 220);
	tl.setxy(0, 5);
	tl.displayhorizontal(120, 220);
	tl.setxy(0, 29);
	tl.displayhorizontal(120, 220);
	tl.displayvertical(0, 4, 29, 219);
	tl.displayvertical(40, 4, 29, 219);
	tl.displayvertical(80, 4, 29, 219);
	tl.displayvertical(118, 4, 29, 219);
}
void graphics::projectsubmission() {
	system("color E4");
	tl.setxy(49, 1);
	cout << "DSA PROJECT WORK IN C++";
	tl.setxy(60, 4);
	cout << char(254);
	for (int p = 5; p <= 19; p++) {
		tl.setxy(60, p);
		cout << char(254);
	}
	tl.setxy(55, 7);
	cout << char(254);
	for (int p = 8; p <= 16; p++) {
		tl.setxy(55, p);
		cout << char(254);
	}
	tl.setxy(65, 7);
	cout << char(254);
	for (int p = 8; p <= 16; p++) {
		tl.setxy(65, p);
		cout << char(254);
	}
	tl.setxy(54, 22);
	cout << "E-Library LMS";
	tl.setxy(35, 9);
	cout << "SUBMITTED TO:" ;
	tl.setxy(35, 10);	
	cout << "Bibaha Sthapit";
	tl.setxy(73, 9);
	cout << "SUBMITTED BY:";
	tl.setxy(73, 10);

	cout << "ARPAN |BIBEK | CHIRAG";

	_getch();

	system("CLS");
	lo.loginscreen();
}