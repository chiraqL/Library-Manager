#include"Headers.h"
tools t;
graphics G;

//Loading graphikshy
void loading::load() {
	t.setxy(40, 5);
	t.Color(2);
	cout << "Please wait! while the program loads.";
	t.setxy(0, 6);
	t.displayhorizontal(120, 254);
	t.setxy(0, 25);
	t.displayhorizontal(120, 254);
	t.setxy(53, 11);
	cout << "Just a moment!" << endl;
	t.setxy(55, 13);
	cout << "LOADING..." << endl;
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
	t.Color(8);
	cout << "Managing and installing is finished.Press any key" << endl;
	(void)_getch();

	system("CLS");
	G.initproject();
}