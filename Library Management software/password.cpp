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
        gh.passwordbox();
        p.setxy(47, 8);
        cout << "Enter Old Password :";
        p.setxy(47, 9);
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
            gh.passwordbox();
            p.setxy(47, 8);
            cout << "Enter New Password :";
            fflush(stdin);
            i = 0;
            p.setxy(47, 9);
            while (1)
            {
                j++;
                ch = _getch();
                if (ch == 13)
                {
                    for (i = 0; st[i] != ' ' && st[i] != '\0'; i++);
                    if (j > 20 || st[i] == ' ')
                    {
                        system("cls");
                        gh.passwordbox();
                        p.setxy(47, 8);
                        cout << " Try again.";
                        _getch();
                        system("cls");
                        reset_pass();
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
            system("cls");
            gh.passwordbox();
            p.setxy(47, 10);
            cout << "Password changed .";
            _getch();
            system("cls");
        }
        else
        {
            system("cls");
            gh.passwordbox();
            p.setxy(47, 8);
            cout << "Password incorrect";
            p.setxy(47, 9);
            cout << "Enter 1 for retry";
            p.setxy(47, 10);
            cin >> i;
            if (i == 1)
            {
                system("cls");
                reset_pass();
            }
            else
            {
                system("cls");
                am.menu();
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
    int i = 0, j = 0;
    char ch, st[21], ch1[21] = { "pass" };
    system("cls");
    gh.passwordbox();
    p.setxy(47, 8);
    cout << "Enter Old Password :";
    p.setxy(47, 9);
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
        gh.passwordbox();
        p.setxy(47, 8);
        cout << "Enter New Password :";
        fflush(stdin);
        i = 0;
        p.setxy(47, 9);
        while (1)
        {
            j++;
            ch = _getch();
            if (ch == 13)
            {
                for (i = 0; st[i] != ' ' && st[i] != '\0'; i++);
                if (j > 20 || st[i] == ' ')
                {
                    system("cls");
                    gh.passwordbox();
                    p.setxy(47, 8);
                    cout << " Try again.";
                    _getch();
                    system("cls");
                    reset_pass();
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
        system("cls");
        gh.passwordbox();
        p.setxy(47, 10);
        cout << "Password changed .";
        _getch();
        system("cls");
    }
    else
    {
        system("cls");
        gh.passwordbox();
        p.setxy(47, 8);
        cout << "Password incorrect";
        p.setxy(47, 9);
        cout << "Enter 1 for retry";
        p.setxy(47, 10);
        cin >> i;
        if (i == 1)
        {
            system("cls");
            reset_pass();
        }
        else
        {
            system("cls");
            am.menu();
        }
    }
}
