#include"allheader.h"
studentmenu st;
librarianpassword lib;
adminpassword ad;
graphics gph;
tools g;
void login::loginscreen() {
	system("CLS");
	gph.footer();
	gph.stdbox();
	g.setxy(47, 5);
	cout << "1.Student login" << endl;
	g.setxy(47, 6);
	cout << "2.Librarian Login" << endl;
	g.setxy(47, 7);
	cout << "3.Administrator Login" << endl;
	g.setxy(47, 8);
	cout << "4.Exit program" << endl;
	g.setxy(47, 19);
	cout << "Choose option";
	g.setxy(47, 20);
	cin >> n;
	switch (n) {
	case 1: {
		system("CLS");

		st.menu();
		break;
	}
	case 2: {
		system("CLS");
		lib.enter_pass();
		break;
	}
	case 3:{
		system("CLS");
		ad.enter_pass();
		break;
	}
	case 4:
	{
		//credits function
		_getch();
		return ;

	}
}
}