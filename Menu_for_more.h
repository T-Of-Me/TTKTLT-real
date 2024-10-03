#include "Thu_Vien.h"

void Menu_for_display_extra(int Option)
{
    system("cls");
    font(11);
    cout << "---- Student Management Program ----" << endl;
    for (int i = 1; i <= 2; i++)
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
            cout << "  display by id class " << endl;
            break;
        case 2:
            cout << "  Display by average score " << endl;
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Menu_for_display()
{
    int Option = 1;
    char keyboard;
    while (true)
    {

        do
        {
            Menu_for_display_extra(Option);
            keyboard = getch();
            switch (keyboard)
            {
            case 72:
                if (Option > 1)
                    Option--;
                break;
            case 80:
                if (Option < 2)
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
            Display_Data_By_Id_Class();

            getch();
            break;
        case 2:
            system("cls");
            DisplayData_By_Average_score();

            getch();
            break;
        }
        if (keyboard == 13)
        {
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Menu_Algorithm_average_extra(int Option) // có thể dùng lại cho các menu sắp xếp các tiêu chí khác
{
    system("cls");
    font(11);
    cout << "---- Algorithm selection ----" << endl;
    for (int i = 1; i <= 3; i++)
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
            cout << "bubble sort " << endl;
            break;
        case 2:
            cout << "selection sort " << endl;
            break;
        case 3:
            cout << "merge sort " << endl;
            break;
        }
    }
}
void Menu_Algorithm_average()
{
    int Option = 1;
    char keyboard;
    while (true)
    {
        do
        {
            Menu_Algorithm_average_extra(Option);
            keyboard = getch();
            switch (keyboard)
            {
            case 72:
                if (Option > 1)
                    Option--;
                break;
            case 80:
                if (Option < 3)
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
            Bubble_sort_end();
            MakeUp();
            getch();
            break;
        case 2:
            system("cls");
            Selection_sort_end();
            MakeUp();
            getch();
            break;
        case 3:
            system("cls");
            Merge_sort_end();
            MakeUp();
            getch();
            break;
        }
        if (keyboard == 13)
        {
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Menu_Algorithm_Name()
{
    int Option = 1;
    char keyboard;
    while (true)
    {
        do
        {
            Menu_Algorithm_average_extra(Option);
            keyboard = getch();
            switch (keyboard)
            {
            case 72:
                if (Option > 1)
                    Option--;
                break;
            case 80:
                if (Option < 3)
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
            Name_Bubble_sort();
            MakeUp();
            getch();
            break;
        case 2:
            system("cls");
            // Name_Selection_Sort();
            Name_Selection_sort();
            MakeUp();
            getch();
            break;
        case 3:
            system("cls");
            // Name_Merge_sort();
            Name_Merge_sort();
            MakeUp();
            getch();
            break;
        }
        if (keyboard == 13)
        {
            break;
        }
    }
}

void Menu_Algorithm_Date()
{
    int Option = 1;
    char keyboard;
    while (true)
    {
        do
        {
            Menu_Algorithm_average_extra(Option);
            keyboard = getch();
            switch (keyboard)
            {
            case 72:
                if (Option > 1)
                    Option--;
                break;
            case 80:
                if (Option < 3)
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
            // Name_Bubble_sort();
            Sort_date_bubble();
            MakeUp();
            getch();
            break;
        case 2:
            system("cls");
            // Name_Selection_Sort();
            Sort_date_Selection();
            MakeUp();
            getch();
            break;
        case 3:
            system("cls");
            // Name_Merge_sort();
            Sort_date_Merge();
            MakeUp();
            getch();
            break;
        }
        if (keyboard == 13)
        {
            break;
        }
    }
}
void Menu_Algorithm_Id_Student()
{
    int Option = 1;
    char keyboard;
    while (true)
    {
        do
        {
            Menu_Algorithm_average_extra(Option);
            keyboard = getch();
            switch (keyboard)
            {
            case 72:
                if (Option > 1)
                    Option--;
                break;
            case 80:
                if (Option < 3)
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
            // Name_Bubble_sort();
            Sort_id_bubble();
            MakeUp();
            getch();
            break;
        case 2:
            system("cls");
            // Name_Selection_Sort();
            Sort_id_Selection();
            MakeUp();
            getch();
            break;
        case 3:
            system("cls");
            // Name_Merge_sort();
            Sort_id_merge();
            MakeUp();
            getch();
            break;
        }
        if (keyboard == 13)
        {
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Menu_for_sort_extra(int Option)
{
    system("cls");
    font(11);
    cout << "---- Algorithm selection ----" << endl;
    for (int i = 1; i <= 5; i++)
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
            cout << " sort by average score " << endl;
            break;
        case 2:
            cout << " sort by name " << endl;
            break;
        case 3:
            cout << " sort by Id_class" << endl;
            break;
        case 4:
            cout << " sort by date " << endl;
            break;
        case 5:
            cout << " sort by Id_Student " << endl;
        }
    }
}

void Menu_for_sort()
{
    int Option = 1;
    char keyboard;
    while (true)
    {
        do
        {
            Menu_for_sort_extra(Option);
            keyboard = getch();
            switch (keyboard)
            {
            case 72:
                if (Option > 1)
                    Option--;
                break;
            case 80:
                if (Option < 5)
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
            Menu_Algorithm_average();
            getch();
            break;
        case 2:
            system("cls");
            Menu_Algorithm_Name();
            getch();
            break;
        case 3:
            system("cls");
            Sort_id_class();
            getch();
            break;
        case 4:
            system("cls");
            Menu_Algorithm_Date();
            getch();
            break;
        case 5:
            system("cls");
            Menu_Algorithm_Id_Student();
            getch();
            break;
        }
        if (keyboard == 13)
        {
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////