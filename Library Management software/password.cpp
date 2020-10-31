#include"password.h"
adminmenu am;
librarianmenu lm;
login h;
tools p;
graphics gh;
void adminpassword::enter_pass() {
    {

        system("CLS");
        int i = 0;
        char ch, st[21], ch1[21] = { "pass" };
        
        p.setxy(47, 8);
        cout <<setw(4)<< "ADMINISTRATOR LOGIN";
        p.setxy(47, 10);
        cout << "Enter Password : ";
       
        gh.passwordbox();
        p.setxy(47, 11);
        while (1)
        {
            
            ch = _getch();
            if (ch == 13)
            {
                st[i] = '\0';
                break;
            }
            else if (ch == 8 && i > 0)
            {
                i--;
                cout << "\b \b";
            }
            else
            {
                cout << "*";
                st[i] = ch;
                i++;
            }
        }
        ifstream inf("password.txt");
        inf >> ch1;
        inf.close();
        for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++);
        if (st[i] == '\0' && ch1[i] == '\0')
        {
            system("cls");
            am.menu();
        }
        else
        {
            system("CLS");
            p.setxy(47, 11);
            cout <<setw(4)<< "WRONG PASSWORD";
            gh.passwordbox();
            _getch();
            system("cls");
           
            h.loginscreen();
        }
    }
}

void adminpassword::reset_pass() {
    {
        int i = 0, j = 0;
        char ch, st[21], ch1[21] = { "pass" };
        system("cls");
        cout << "\n\n\t\tEnter Old Password : ";
        while (1)
        {
            ch = _getch();
            if (ch == 13)
            {
                st[i] = '\0';
                break;
            }
            else if (ch == 8 && i > 0)
            {
                i--;
                cout << "\b \b";
            }
            else
            {
                cout << "*";
                st[i] = ch;
                i++;
            }
        }
        ifstream intf("password.txt");
        intf >> ch1;
        intf.close();
        for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++);
        if (st[i] == '\0' && ch1[i] == '\0')
        {
            system("cls");
            cout << "\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
            cout << "\n\t\tEnter New Password : ";
            fflush(stdin);
            i = 0;
            while (1)
            {
                j++;
                ch = _getch();
                if (ch == 13)
                {
                    for (i = 0; st[i] != ' ' && st[i] != '\0'; i++);
                    if (j > 20 || st[i] == ' ')
                    {
                        cout << "\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
                        _getch();
                        system("cls");
                        reset_pass();
                        //function to be called
                    }
                    st[i] = '\0';
                    break;
                }
                else if (ch == 8 && i > 0)
                {
                    i--;
                    cout << "\b \b";
                }
                else
                {
                    cout << "*";
                    st[i] = ch;
                    i++;
                }
            }
            ofstream outf("password.txt");
            outf << st;
            outf.close();
            cout << "\n\n\t\tYour Password has been changed Successfully.";
            cout << "\n\t\tPress any key to continue......";
            _getch();
            system("cls");
            //function to be called
        }
        else
        {
            cout << "\n\n\t\tPassword is incorrect.....\n";
            cout << "\n\t\tEnter 1 for retry or 2 for menu";
            cin >> i;
            if (i == 1)
            {
                system("cls");
                reset_pass();
            }
            else
            {
                system("cls");
                //funtion to be called
            }
        }
    }
}
void librarianpassword::enter_pass() {
    {
        system("CLS");
        int i = 0;
        p.setxy(47, 8);
        cout << setw(4) << "LIBRARIAN LOGIN";
        char ch, st[21], ch1[21] = { "pass" };
        p.setxy(47, 10);
        cout << "Enter Password : ";
        gh.passwordbox();
        p.setxy(47, 11);
        while (1)
        {
            ch = _getch();
            if (ch == 13)
            {
                st[i] = '\0';
                break;
            }
            else if (ch == 8 && i > 0)
            {
                i--;
                cout << "\b \b";
            }
            else
            {
                cout << "*";
                st[i] = ch;
                i++;
            }
        }
        ifstream inf("passwordlib.txt");
        inf >> ch1;
        inf.close();
        for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++);
        if (st[i] == '\0' && ch1[i] == '\0')
        {
            system("cls");
            lm.menu();
        }
        else
        {
            system("cls");
                p.setxy(47, 11);
            cout << setw(4) << "WRONG PASSWORD";
            gh.passwordbox();
            _getch();
            system("cls");
            h.loginscreen();
        }
    }
}
void librarianpassword::reset_pass() {
    {
        int i = 0, j = 0;
        char ch, st[21], ch1[21] = { "pass" };
        system("cls");
        cout << "\n\n\t\tEnter Old Password : ";
        while (1)
        {
            ch = _getch();
            if (ch == 13)
            {
                st[i] = '\0';
                break;
            }
            else if (ch == 8 && i > 0)
            {
                i--;
                cout << "\b \b";
            }
            else
            {
                cout << "*";
                st[i] = ch;
                i++;
            }
        }
        ifstream intf("passwordlib.txt");
        intf >> ch1;
        intf.close();
        for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++);
        if (st[i] == '\0' && ch1[i] == '\0')
        {
            system("cls");
            cout << "\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
            cout << "\n\t\tEnter New Password : ";
            fflush(stdin);
            i = 0;
            while (1)
            {
                j++;
                ch = _getch();
                if (ch == 13)
                {
                    for (i = 0; st[i] != ' ' && st[i] != '\0'; i++);
                    if (j > 20 || st[i] == ' ')
                    {
                        cout << "\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
                        _getch();
                        system("cls");
                        reset_pass();
                        //function to be called
                    }
                    st[i] = '\0';
                    break;
                }
                else if (ch == 8 && i > 0)
                {
                    i--;
                    cout << "\b \b";
                }
                else
                {
                    cout << "*";
                    st[i] = ch;
                    i++;
                }
            }
            ofstream outf("passwordlib.txt");
            outf << st;
            outf.close();
            cout << "\n\n\t\tYour Password has been changed Successfully.";
            cout << "\n\t\tPress any key to continue......";
            _getch();
            system("cls");
            //function to be called
        }
        else
        {
            cout << "\n\n\t\tPassword is incorrect.....\n";
            cout << "\n\t\tEnter 1 for retry or 2 for menu";
            cin >> i;
            if (i == 1)
            {
                system("cls");
                reset_pass();
            }
            else
            {
                system("cls");
                //funtion to be called
            }
        }
    }
}