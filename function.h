#include "Thu_Vien.h"
#include <iomanip>
#include "SinhVien.h"
void table(vector<SinhVien> sinhvien)
{
    int sum = sinhvien.size();
    for (int i = 0; i < 113; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "|STT  |" << setw(25) << left << "NAME" << setw(20) << left << "|ID_CLASS" << setw(20) << left << "|ID_STUDENT" << setw(20) << left << "|AVERAGE_SCORE" << setw(20) << left << "|DAY" << setw(20) << "|";
    cout << endl;
    for (int i = 0; i < 113; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < sum; i++)
    {
        string day = to_string(sinhvien[i].Return_day());
        string month = to_string(sinhvien[i].Return_month());
        string year = to_string(sinhvien[i].Return_year());
        string date = day + "/" + month + "/" + year;
        cout << "|" << setw(5) << i + 1 << "|" << setw(25) << sinhvien[i].Return_name() << "|" << setw(19) << sinhvien[i].Return_id_class() << "|" << setw(20) << sinhvien[i].Return_id_student() << "|" << setw(20) << sinhvien[i].Return_Average_score() << "|" << setw(19) << date << setw(0) << "|";
        cout << endl;
    }
}
// DISPLAY //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display_Data_By_Id_Class()
{
    vector<SinhVien> sinhvien; // vector tên sinh viên
    ifstream File1("DATA.txt");
    cout << "id class is";
    string Id;
    getline(cin, Id);
    if (!File1)
    {
        cerr << "Unable to open file DATA.txt" << endl;
        return;
    }
    SinhVien sv;
    bool check = false;
    while (File1 >> sv)
    {

        if (sv.Return_id_class() == Id)
        {
            check = true;
            sinhvien.push_back(sv);
        }
    }
    File1.close();
    if (!check)
    {
        cout << "Id_class not exist" << endl;
    }
    else
    {

        table(sinhvien);
    }
    cout << "Enter to return" << endl;
}

void DisplayData_By_Average_score()
{
    vector<SinhVien> sinhvien; // vector tên sinh viên
    ifstream File1("DATA.txt");
    cout << "Enter Average score: ";
    float Id;
    cin >> Id;
    if (!File1)
    {
        cerr << "Unable to open file DATA.txt";
        return;
    }
    SinhVien sv;
    bool check = false;
    while (File1 >> sv)
    {

        if (sv.Return_Average_score() == Id)
        {
            check = true;
            sinhvien.push_back(sv);
        }
    }
    if (check == false)
    {
        font(12);
        cout << "Average score not exist ";
    }
    else
    {
        table(sinhvien);
    }
    File1.close();
    cout << endl;
    cout << "Enter to return";
}
// INSERT //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertData()
{
    SinhVien x;
    x.InsertFile();
}
// SORT //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool increase(SinhVien &a, SinhVien &b)
{
    return a.Return_Average_score() < b.Return_Average_score();
}
void sorting_average_score_selection_sort(vector<SinhVien> &sinhvien)
{

    int n = sinhvien.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (sinhvien[j].Return_Average_score() < sinhvien[min_idx].Return_Average_score())
            {
                min_idx = j;
            }
        }
        swap(sinhvien[min_idx], sinhvien[i]);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void merge(vector<SinhVien> &sinhvien, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<SinhVien> leftArray(n1);
    vector<SinhVien> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = sinhvien[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = sinhvien[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i].Return_Average_score() <= rightArray[j].Return_Average_score())
        {
            sinhvien[k] = leftArray[i];
            i++;
        }
        else
        {
            sinhvien[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        sinhvien[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        sinhvien[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(vector<SinhVien> &sinhvien, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(sinhvien, left, mid);
    mergeSort(sinhvien, mid + 1, right);
    merge(sinhvien, left, mid, right);
}

void sorting_average_score_merge_sort(vector<SinhVien> &sinhvien)
{

    mergeSort(sinhvien, 0, sinhvien.size() - 1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sorting_average_score_bubble_sort(vector<SinhVien> &sinhvien)
{
    int n = sinhvien.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (sinhvien[j].Return_Average_score() > sinhvien[j + 1].Return_Average_score())
            {
                swap(sinhvien[j], sinhvien[j + 1]);
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<SinhVien> Selection_sort()
{
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báo
    if (!infile.is_open())                // nếu không mở được
    {
        font(12);
        cerr << "Error" << endl; // lỗi
        return sinhvien;
    }
    SinhVien s;         // khai báo đối tượng
    while (infile >> s) // đọc file
    {
        sinhvien.push_back(s); // đưa vào vector
    }
    infile.close(); // trả về vector
    sorting_average_score_selection_sort(sinhvien);
    return sinhvien;
}
vector<SinhVien> Merge_sort()
{
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báo
    if (!infile.is_open())                // nếu không mở được
    {
        font(12);
        cerr << "Error" << endl; // lỗi
        return sinhvien;
    }
    SinhVien s;         // khai báo đối tượng
    while (infile >> s) // đọc file
    {
        sinhvien.push_back(s); // đưa vào vector
    }
    infile.close(); // trả về vector
    sorting_average_score_merge_sort(sinhvien);
    return sinhvien;
}
vector<SinhVien> Bubble_sort()
{
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báo
    if (!infile.is_open())                // nếu không mở được
    {
        font(12);
        cerr << "Error" << endl; // lỗi
        return sinhvien;
    }
    SinhVien s;         // khai báo đối tượng
    while (infile >> s) // đọc file
    {
        sinhvien.push_back(s); // đưa vào vector
    }
    infile.close(); // trả về vector
    sorting_average_score_bubble_sort(sinhvien);
    return sinhvien;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Selection_sort_end()
{

    auto start = high_resolution_clock::now();
    font(6);
    table(Selection_sort());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    font(5);
    cout << "Sort after : " << duration << " microseconds" << endl;
    cout << "enter to return";
}
void Merge_sort_end()
{
    auto start = high_resolution_clock::now();
    font(6);
    table(Merge_sort());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    font(5);
    cout << "Sort after : " << duration << " microseconds" << endl;
    cout << "enter to return";
}
void Bubble_sort_end()
{

    auto start = high_resolution_clock::now();
    font(6);
    table(Bubble_sort());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    font(5);
    cout << "Sort after : " << duration << " microseconds" << endl;
    cout << "enter to return";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string cut_name(std::string s, int i)
{
    string ten = "", dem1 = "", dem2 = "", ho = "";

    // Tách các phần tử của tên
    vector<string> parts;
    string temp = "";
    for (char ch : s)
    {
        if (ch == ' ')
        {
            if (!temp.empty())
            {
                parts.push_back(temp);
                temp.clear();
            }
        }
        else
        {
            temp += ch;
        }
    }
    if (!temp.empty())
        parts.push_back(temp); // Thêm phần cuối cùng

    if (i == 1)
        return parts.back(); // Lấy tên
    if (i == 2 && parts.size() > 2)
        return parts[parts.size() - 2]; // Lấy đệm 1
    if (i == 3 && parts.size() > 3)
        return parts[parts.size() - 3]; // Lấy đệm 2
    if (i == 4)
        return parts.front(); // Lấy họ

    return ""; // Trường hợp không có đủ thông tin
}

void Name_Bubble_Sort_extra(vector<SinhVien> &ds)
{
    for (int i = 0; i < (int)ds.size() - 1; i++)
    {
        for (int j = (int)ds.size() - 1; j > i; j--)
        {
            // So sánh tên
            string ten1 = cut_name(ds[j].Return_name(), 1);
            string ten2 = cut_name(ds[j - 1].Return_name(), 1);

            if (ten1 < ten2)
            {
                swap(ds[j - 1], ds[j]);
            }
            else if (ten1 == ten2)
            {
                // So sánh tên đệm
                string dem1 = cut_name(ds[j].Return_name(), 2);
                string dem2 = cut_name(ds[j - 1].Return_name(), 2);

                if (dem1 < dem2)
                {
                    swap(ds[j - 1], ds[j]);
                }
                else if (dem1 == dem2)
                {
                    // So sánh tên đệm thứ 2 (nếu có)
                    string dem11 = cut_name(ds[j].Return_name(), 3);
                    string dem22 = cut_name(ds[j - 1].Return_name(), 3);

                    if (dem11 < dem22)
                    {
                        swap(ds[j - 1], ds[j]);
                    }
                    else if (dem11 == dem22)
                    {
                        // So sánh họ
                        string ho1 = cut_name(ds[j].Return_name(), 4);
                        string ho2 = cut_name(ds[j - 1].Return_name(), 4);

                        if (ho1 < ho2)
                        {
                            swap(ds[j - 1], ds[j]);
                        }
                    }
                }
            }
        }
    }
}

// Hàm đọc danh sách sinh viên và sắp xếp
std::vector<SinhVien> Name_Bubble_Sort_dental()
{
    std::ifstream infile("DATA.txt", std::ios::in);
    std::vector<SinhVien> sinhvien;
    if (!infile.is_open())
    {
        std::cerr << "Error: Unable to open file." << std::endl;
        return sinhvien;
    }
    SinhVien s;
    while (infile >> s)
    {
        sinhvien.push_back(s);
    }
    infile.close();
    Name_Bubble_Sort_extra(sinhvien);
    return sinhvien;
}

void Name_Bubble_sort()
{
    auto start = high_resolution_clock::now();
    table(Name_Bubble_Sort_dental());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    cout << "Sort finished in: " << duration << " microseconds" << endl;
    cout << "Press Enter to return";
    cin.get(); // Chờ người dùng nhấn Enter
}

// selection sort name 

void Name_Selection_Sort(vector<SinhVien> &ds) {
    for (int i = 0; i < ds.size() - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < ds.size(); j++) {
            string ten1 = cut_name(ds[j].Return_name(), 1);
            string ten2 = cut_name(ds[min_idx].Return_name(), 1);

            if (ten1 < ten2) {
                min_idx = j;
            } else if (ten1 == ten2) {
                string dem1 = cut_name(ds[j].Return_name(), 2);
                string dem2 = cut_name(ds[min_idx].Return_name(), 2);

                if (dem1 < dem2) {
                    min_idx = j;
                } else if (dem1 == dem2) {
                    string dem11 = cut_name(ds[j].Return_name(), 3);
                    string dem22 = cut_name(ds[min_idx].Return_name(), 3);

                    if (dem11 < dem22) {
                        min_idx = j;
                    } else if (dem11 == dem22) {
                        string ho1 = cut_name(ds[j].Return_name(), 4);
                        string ho2 = cut_name(ds[min_idx].Return_name(), 4);

                        if (ho1 < ho2) {
                            min_idx = j;
                        }
                    }
                }
            }
        }
        swap(ds[min_idx], ds[i]);
    }
}

std::vector<SinhVien> Name_Selection_Sort_dental() {
    std::ifstream infile("DATA.txt", std::ios::in);
    std::vector<SinhVien> sinhvien;
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return sinhvien;
    }
    SinhVien s;
    while (infile >> s) {
        sinhvien.push_back(s);
    }
    infile.close();
    Name_Selection_Sort(sinhvien);
    return sinhvien;
}

void Name_Selection_sort() {
    auto start = high_resolution_clock::now();
    table(Name_Selection_Sort_dental());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    cout << "Sort finished in: " << duration << " microseconds" << endl;
    cout << "Press Enter to return";
    cin.get();
}

// merge sort name 

bool compare_names(  SinhVien &a,   SinhVien &b) {
    string ten1 = cut_name(a.Return_name(), 1);
    string ten2 = cut_name(b.Return_name(), 1);

    if (ten1 != ten2) return ten1 < ten2;

    string dem1 = cut_name(a.Return_name(), 2);
    string dem2 = cut_name(b.Return_name(), 2);

    if (dem1 != dem2) return dem1 < dem2;

    string dem11 = cut_name(a.Return_name(), 3);
    string dem22 = cut_name(b.Return_name(), 3);

    if (dem11 != dem22) return dem11 < dem22;

    string ho1 = cut_name(a.Return_name(), 4);
    string ho2 = cut_name(b.Return_name(), 4);

    return ho1 < ho2;
}

void merge_NAME(vector<SinhVien> &ds, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<SinhVien> L(n1);
    vector<SinhVien> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = ds[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = ds[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare_names(L[i], R[j])) {
            ds[k] = L[i];
            i++;
        } else {
            ds[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        ds[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        ds[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_name(vector<SinhVien> &ds, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_name(ds, left, mid);
        merge_sort_name(ds, mid + 1, right);

        merge_NAME(ds, left, mid, right);
    }
}

std::vector<SinhVien> Name_Merge_Sort_dental() {
    std::ifstream infile("DATA.txt", std::ios::in);
    std::vector<SinhVien> sinhvien;
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return sinhvien;
    }
    SinhVien s;
    while (infile >> s) {
        sinhvien.push_back(s);
    }
    infile.close();
    merge_sort_name(sinhvien, 0, sinhvien.size() - 1);
    return sinhvien;
}

void Name_Merge_sort() {
    auto start = high_resolution_clock::now();
    table(Name_Merge_Sort_dental());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    cout << "Sort finished in: " << duration << " microseconds" << endl;
    cout << "Press Enter to return";
    cin.get();
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// sort id class
void removeDuplicates(string arr[], int &n)
{
    if (n == 0)
        return;

    int newSize = 0;
    for (int i = 0; i < n; ++i)
    {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; ++j)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            arr[newSize++] = arr[i];
        }
    }
    n = newSize;
}

void Sort_id_class()
{
    vector<SinhVien> sinhvien[10000]; // vector tên sinh viên
    SinhVien sv;
    string *Listname = new string[10000];
    int i = 0;
    ifstream File1("DATA.txt");
    while (File1 >> sv)
    {
        Listname[i] = sv.Return_id_class();
        i++;
    }
    File1.close();
    int num = i;
    removeDuplicates(Listname, num);
    for (int i = 0; i < num; i++)
    {
        bool check = false;
        font(10 + i);
        cout << "student in class :" << Listname[i] << endl;
        ifstream File1("DATA.txt");
        while (File1 >> sv)
        {

            if (sv.Return_id_class() == Listname[i])
            {
                check = true;
                sinhvien[i].push_back(sv);
            }
        }
        if (!check)
        {
            cout << "Id_class not exist" << endl;
        }
        else
        {
            table(sinhvien[i]);
            cout << endl;
            cout << endl;
            cout << endl;

            File1.close();
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// sort date
bool Xor_Date_smaller(SinhVien &a, SinhVien &b)
{
    if (a.Return_year() != b.Return_year())
        return a.Return_year() < b.Return_year();
    if (a.Return_month() != b.Return_month())
        return a.Return_month() < b.Return_month();
    return a.Return_day() < b.Return_day();
}
void Sort_date_Selection()
{
    font(2);
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báo
    SinhVien s;                           // khai báo đối tượng
    while (infile >> s)                   // đọc file
    {
        sinhvien.push_back(s); // đưa vào vector
    }
    infile.close(); // đóng file
    int n = sinhvien.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (Xor_Date_smaller(sinhvien[j], sinhvien[minIndex])) // nếu j < minIndex
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(sinhvien[i], sinhvien[minIndex]);
        }
    }
    table(sinhvien);
}

void Sort_date_bubble()
{
    font(2);
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báo
    SinhVien s;                           // khai báo đối tượng
    while (infile >> s)                   // đọc file
    {
        sinhvien.push_back(s); // đưa vào vector
    }
    infile.close(); // đóng file
    int n = sinhvien.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Xor_Date_smaller(sinhvien[j + 1], sinhvien[j])) // nếu j+1 < j
            {
                std::swap(sinhvien[j], sinhvien[j + 1]);
            }
        }
    }
    table(sinhvien);
}

void merge_date(std::vector<SinhVien>& sinhvien, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<SinhVien> L(n1);
    std::vector<SinhVien> R(n2);

    std::copy(sinhvien.begin() + left, sinhvien.begin() + mid + 1, L.begin());
    std::copy(sinhvien.begin() + mid + 1, sinhvien.begin() + right + 1, R.begin());

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Xor_Date_smaller(L[i], R[j])) {
            sinhvien[k] = L[i];
            i++;
        } else {
            sinhvien[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        sinhvien[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        sinhvien[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort_Date(std::vector<SinhVien>& sinhvien, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort_Date(sinhvien, left, mid);
        mergeSort_Date(sinhvien, mid + 1, right);

        merge_date(sinhvien, left, mid, right);
    }
}

void Sort_date_Merge() {
    font(2);
    std::ifstream infile("DATA.txt", std::ios::in);
    std::vector<SinhVien> sinhvien;
    SinhVien s;
    while (infile >> s) {
        sinhvien.push_back(s);
    }
    infile.close();

    mergeSort_Date(sinhvien, 0, sinhvien.size() - 1);

    table(sinhvien);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// sort id
void sorting_ids(vector<SinhVien> &sinhvien)
{

    int n = sinhvien.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (sinhvien[j].Return_id_student() < sinhvien[min_idx].Return_id_student())
            {
                min_idx = j;
            }
        }
        swap(sinhvien[min_idx], sinhvien[i]);
    }
}

vector<SinhVien> Selection_sort_id()
{
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báo
    if (!infile.is_open())                // nếu không mở được
    {
        font(12);
        cerr << "Error" << endl; // lỗi
        return sinhvien;
    }
    SinhVien s;         // khai báo đối tượng
    while (infile >> s) // đọc file
    {
        sinhvien.push_back(s); // đưa vào vector
    }
    infile.close(); // trả về vector
    sorting_ids(sinhvien);
    return sinhvien;
}
void Sort_id_Selection()
{

    auto start = high_resolution_clock::now();
    font(6);
    table(Selection_sort_id());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    font(5);
    cout << "Sort after : " << duration << " microseconds" << endl;
    cout << "enter to return";
}

// bubble
 
vector<SinhVien> Bubble_sort_id()
{
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báo
    if (!infile.is_open())                // nếu không mở được
    {
        font(12);
        cerr << "Error" << endl; // lỗi
        return sinhvien;
    }
    SinhVien s;         // khai báo đối tượng
    while (infile >> s) // đọc file
    {
        sinhvien.push_back(s); // đưa vào vector
    }
    infile.close(); // trả về vector
    sorting_ids(sinhvien);
    return sinhvien;
}

void Sort_id_bubble()
{
    auto start = high_resolution_clock::now();
    font(6);
    table(Bubble_sort_id());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    font(5);
    cout << "Sort after : " << duration << " microseconds" << endl;
    cout << "enter to return";
}
// merge 
void merge_id(std::vector<SinhVien>& sinhvien, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<SinhVien> L(n1);
    std::vector<SinhVien> R(n2);

    std::copy(sinhvien.begin() + left, sinhvien.begin() + mid + 1, L.begin());
    std::copy(sinhvien.begin() + mid + 1, sinhvien.begin() + right + 1, R.begin());

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].Return_id_student() <= R[j].Return_id_student()) {
            sinhvien[k] = L[i];
            i++;
        } else {
            sinhvien[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        sinhvien[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        sinhvien[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort_id(std::vector<SinhVien>& sinhvien, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort_id(sinhvien, left, mid);
        mergeSort_id(sinhvien, mid + 1, right);

        merge_id(sinhvien, left, mid, right);
    }
}

vector<SinhVien> Merge_sort_id()
{
    ifstream infile("DATA.txt", ios::in); // đọc file
    vector<SinhVien> sinhvien;            // khai báo
    if (!infile.is_open())                // nếu không mở được
    {
        font(12);
        cerr << "Error" << endl; // lỗi
        return sinhvien;
    }
    SinhVien s;         // khai báo đối tượng
    while (infile >> s) // đọc file
    {
        sinhvien.push_back(s); // đưa vào vector
    }
    infile.close(); // trả về vector
    mergeSort_id(sinhvien, 0, sinhvien.size() - 1);
    return sinhvien;
}

void Sort_id_merge()
{
    auto start = high_resolution_clock::now();
    font(6);
    table(Merge_sort_id());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    font(5);
    cout << "Sort after : " << duration << " microseconds" << endl;
    cout << "enter to return";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////