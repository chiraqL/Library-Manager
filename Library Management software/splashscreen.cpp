#include"allheader.h"
tools t;

graphics gl;
void loading::load() {
    int x = 0;
    t.setxy(1, 5);
    t.Color(2);
    cout << "Please wait program is managing in your computer system";
    t.setxy(0, 6);
    t.displayhorizontal(146, 1);
    t.setxy(0, 25);
    t.displayhorizontal(146, 1);
    t.setxy(45, 11);
    cout << "Please wait few seconds" << endl;
    t.setxy(50, 12);
    cout << "LOADING!!!!" << endl;
    for (int p = 10; p <= 110; p++) {
        t.Color(4); {
            t.setxy(p, 15);
            Sleep(10);
        }
        cout << char(219);
        t.setxy(55, 16);
        t.Color(4);
        cout << x << "%";
        x = x + 1;
    }
    t.setxy(33, 22);
    t.Color(7);
    cout << "Managing and installing is finished.Press any key" << endl;
    _getch();
    system("CLS");
    gl.projectsubmission();
    
    
    
}