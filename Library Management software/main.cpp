#include "Headers.h"

loading L;
tools T;

int main() {
	system("MODE CON COLS=120 LINES=30");		//Size of console
	T.fullscreen();								
	T.fontsize(25, 34);
	L.load();									//Everything in here
	(void)_getch();
}