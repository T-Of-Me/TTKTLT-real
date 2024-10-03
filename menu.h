
#include "Thu_Vien.h"
void font(int colour)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, colour);
}
void Menu(int Option)
{
    system("cls");
    font(11);
    cout << "---- Student Management Program ----" << endl;
    for (int i = 1; i <= 7; i++)
    {
        if (i == Option)
        {
            font(13);
            cout << "*  =>>     ";
        }
        else
        {
            font(8);
            cout << "*     ";
        }
        switch (i)
        {
        case 1:
            cout << "  Add " << endl;
            break;
        case 2:
            cout << "  Display " << endl;
            break;
        case 3:
            cout << "  Sort   " << endl;
            break;
        case 4:
            cout << "  Search    " << endl;
            break;
        case 5:
            cout << "  Sum   " << endl;
            break;
        case 6:
            cout << "  Change  " << endl;
            break;
        case 7:
            cout << "  Exit  " << endl;
            break;
        }
    }
}

 