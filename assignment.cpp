#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

class details
{
private:
    struct customer
    {
        char name[50];
        char phone_number[20];
    } c;

    fstream my_file;

public:
    details();
    void addrecord();
    void recordlist();
    void search();
    void namefile();
    void numberfile();
    void exit();
};
int main()
{
    char choice;
    details d;
   
        cout << "Enter the operation\n";
        cout << "a.Add Record\n";
        cout << "b.List of Record\n";
        cout << "c.Search Record\n";
        cout << "d.name files\n";
        cout << "e.number files\n";
        std::cin >> choice;
        switch (choice)
        {
        case 'a':
            d.addrecord();
            break;
        case 'c':
            d.search();
            break;
        case 'b':
            d.recordlist();
            break;
        case 'd':
            d.namefile();
            break;
        case 'e':
            d.numberfile();
            break;
        default:
            cout << "Invalid grade\n";
        }
  

    return 0;
}

details::details()
{
    my_file.open("customer.txt", ios::binary | ios::in | ios::out);

    if (!my_file)
    {
        cout << "File not found\n";
        exit();
    }
}
void details::addrecord()
{
    int n;
    cout << "Enter number of Customers\n";
    cin >> n;
    my_file.seekp(0, ios::end);

    while (n > 0)
    {
        {
            cout << "Enter name of Customer\n";
            cin >> c.name;

            cout << "Enter phone_number\n";
            cin >> c.phone_number;
        }
        my_file.write((char *)&c, sizeof(c));

        n--;
    }
}
void details::recordlist()
{
    int i = 0, p;
    my_file.seekg(0, ios::beg);
    while (my_file.read((char *)&c, sizeof(c)))
    {

        cout << endl
             << ++i << " "
             << setw(6) << c.name
             << setw(30) << c.phone_number;
    }

    cout << "\n";
    cout << "\n";
}
void details::search()
{
    char cname[10];
    int flag = 0;
    cout << "Enter Customer Name\n";
    cin >> cname;
    my_file.seekg(0, ios::beg);
    while (my_file.read((char *)&c, sizeof(c)))
    {
        if (strcmp(c.name, cname) == 0)
        {
            cout << c.name;
            cout << setw(20) << c.phone_number << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "No records found\n";
    }
    my_file.close();
    cout << "\n";
    cout << "\n";
}
void details::exit()
{
    my_file.close();
}
void details::namefile()
{
    fstream f1;
    int i = 0;
    f1.open("name.txt", ios::binary | ios::in | ios::out);
    my_file.seekg(0, ios::beg);
    while (my_file.read((char *)&c, sizeof(c)))
    {
        if (c.name)
            f1.write((char *)&c, sizeof(c));
    }
    f1.close();
    my_file.close();
    f1.open("name.txt", ios::binary | ios::in | ios::out);
    while (f1.read((char *)&c, sizeof(c)))
    {
        cout << ++i;
        cout.width(10);
        cout << c.name;
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";
}
void details::numberfile()
{
    fstream f2;
    int i = 0;
    f2.open("number.txt", ios::binary | ios::in | ios::out);
    my_file.seekg(0, ios::beg);
    while (my_file.read((char *)&c, sizeof(c)))
    {
        if (c.phone_number)
            f2.write((char *)&c, sizeof(c));
    }
    f2.close();
    my_file.close();
    f2.open("name.txt", ios::binary | ios::in | ios::out);
    while (f2.read((char *)&c, sizeof(c)))
    {

        cout.width(10);
        cout << c.phone_number;
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";
}
