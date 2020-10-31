#include "Headers.h"

int main() {
	system("MODE CON COLS=120 LINES=30"); //Size of console
	loading lib;
	lib.load();							  //Everything in here
	(void)_getch();
}