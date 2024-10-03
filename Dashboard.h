#include "menu.h"
#include "Thu_Vien.h"
#include "MakeUp.h"
#include "function.h"
#include "Menu_for_more.h"
void Dashboard()
{
    int Option = 1;
    char keyboard;
    while (true)
    {
        do
        {
            Menu(Option);
            keyboard = getch();
            switch (keyboard)
            {
            case 72:
                if (Option > 1)
                    Option--;
                break;
            case 80:
                if (Option < 7)
                    Option++;
                break;
            default:
                break;
            }
        } while (keyboard != 13);
        switch (Option)
        {
        case 1:
            system("cls");
            font(10);
            MakeUp();
            font(12);
            cout << "------------------=====InSert DATA=====-------------------" << endl;
            font(10);
            InsertData();
            MakeUp();
            getch();
            break;
        case 2:
            system("cls");
            font(10);
            MakeUp();
            font(12);
            cout << "-------------------=====DISPLAY=====-------------------" << endl;
            font(10);
            Menu_for_display();
            MakeUp();
            getch();
            break;
        case 3:
            system("cls");
            font(10);
            MakeUp();
            font(12);
            cout << "-------------------=====SORT DATA=====-------------------" << endl;
            font(10);
            Menu_for_sort();
            MakeUp();
            getch();
            break;
        case 4:
            system("cls");
            font(10);
            MakeUp();
            font(12);
            cout << "-------------------=====SEARCH DATA=====-------------------" << endl;
            font(10);
            // SearchData();
            MakeUp();
            getch();
            break;
            break;
        case 5:
            system("cls");
            font(10);
            MakeUp();
            font(12);
            cout << "-------------------=====SUM DATA=====-------------------" << endl;
            font(10);
            // SumData();
            MakeUp();
            getch();
            break;
            break;
        case 6:
            system("cls");
            font(10);
            MakeUp();
            font(12);
            cout << "-------------------=====CHANGE DATA======-------------------" << endl;
            font(10);
            // InsertData();
            MakeUp();
            getch();
            break;
        case 7:
            system("cls");
            font(10);
            MakeUp();
            font(12);
            cout << "-------------------=====EXIT======-------------------" << endl;
            font(10);
            // InsertData();
            MakeUp();
            getch();
            break;
        }
    }
}