#pragma once
#include "Headers.h"
class tools {
private:
	COORD c = { 0, 0 };
	int count = 0;
public:
	void displayhorizontal(int total, int ascii);
	void Color(int color);
	void setxy(int x, int y);
	void displayvertical(int posx,int posy1,int posy2, int ascii);
	/*void background();*/
	int bookcounter();
	int studentcounter();
	void fontsize(int , int );
};