#include"Headers.h"
tools t;
graphics gl;

void loading::load() {
	//Loading Graphikshy
	t.setxy(33, 5);
	t.Color(2);
	cout << "Please wait! Program is managing in your computer system";
	t.setxy(0, 6);
	t.displayhorizontal(120, 254);
	t.setxy(0, 25);
	t.displayhorizontal(120, 254);
	t.setxy(45, 11);
	cout << "Please wait few seconds" << endl;
	t.setxy(50, 12);
	cout << "LOADING!!!!" << endl;
	for (int p = 10; p <= 110; p++) {
		t.Color(4); 
		{
			t.setxy(p, 15);
			Sleep(10);
		}
		cout << char(219);
		t.setxy(55, 16);
		t.Color(4);
		cout << loadP << "%";
		++loadP;
	}
	t.setxy(35, 22);
	t.Color(7);
	cout << "Managing and installing is finished.Press any key" << endl;
	(void)_getch();

	//management
	system("CLS");
	gl.projectsubmission();
}