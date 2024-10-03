#include "Thu_Vien.h"

class SinhVien
{

private:
    string id_class;
    string id_student;
    float average_score;
    string name;
    int day, month, year;

public:
    void SetDate(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void SetId(int cl, string st)
    {
        id_class = cl;
        id_student = st;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string Return_id_class()
    {
        return id_class;
    }
    string Return_id_student()
    {
        return id_student;
    }
    float Return_Average_score()
    {
        return average_score;
    }
    string Return_name()
    {
        return name;
    }
    int Return_day()
    {
        return day;
    }
    int Return_month()
    {
        return month;
    }
    int Return_year()
    {
        return year;
    }
    friend istream &operator>>(istream &in, SinhVien &x)
    {
        in.ignore();
        getline(in, x.id_class);
        getline(in, x.id_student);
        in >> x.average_score;
        in.ignore();
        getline(in, x.name);
        in >> x.day;
        in >> x.month;
        in >> x.year;
        return in;
    };
    friend ostream &operator<<(ostream &out, const SinhVien &x)
    {
        out << x.id_class << endl;
        out << x.id_student << endl;
        out << x.average_score << endl;
        out << x.name << endl;
        out << x.day << endl;
        out << x.month << endl;
        out << x.year << endl;
        return out;
    };
    void insert()
    {
        cout << endl;
        font(14);
        cout << "id_class :";
        getline(cin, id_class);

        do
        {
            cout << "id_student :";
            getline(cin, id_student);
            if (id_student.length() != 8)
            {
                font(12);
                cout << "error syntas" << endl;
                cout << "Id student must 8" << endl;
                font(14);
            }

        } while (id_student.length() != 8);
        cout << "average_score :";
        cin >> average_score;
        cin.ignore();
        cout << "name :";
        getline(cin, name);
        cout << " day :";
        do
        {
            cin >> day;
            if (day < 0 || day > 31)
            {
                font(12);
                cout << " error  " << endl;
                cout << " 0 < month < 31 " << endl;
                font(14);
            }
        } while (day < 0 || day > 31);
        cout << " month :";
        do
        {
            cin >> month;
            if (month < 0 || month > 12)
            {
                font(12);
                cout << " error " << endl;
                cout << " 0 < month < 12 " << endl;
                font(14);
            }
        } while (month < 0 || month > 12);
        cout << " year :";
        do
        {
            cin >> year;
            if (year < 1999 || year > 2024)
            {
                font(12);
                cout << " error " << endl;
                cout << " 1999 < month < 2024 " << endl;
                font(14);
            }

        } while (year < 1999 || year > 2024);
    }
    void InsertFile()
    {
        SinhVien x;
        x.insert();
        ofstream File("DATA.txt", ios::app);
        File << x;
        File.close();
    }
};
