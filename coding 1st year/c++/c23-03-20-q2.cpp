#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char temp[256];
    ifstream fin("1file1.txt"); // opening file by constructor
    if (!fin)
    {
        cout << "Error in opening the file." << endl;
        exit(1);
    }
    cout << "\nReading without loop." << endl;
    fin.getline(temp, 256);
    cout << temp << endl;
    fin.close();

    ifstream fin1;
    fin1.open("1file1.txt"); // opening file by open function
    if (!fin1)
    {
        cout << "Error in opening the file." << endl;
        exit(1);
    }
    cout << "\nReading with while fin loop." << endl;
    while (fin1)
    {
        fin1.getline(temp, 256);
        cout << temp << endl;
    }
    fin1.close();

    cout << "Reading with while eof==0 loop." << endl;
    ifstream fin2("1file1.txt");
    if (!fin2)
    {
        cout << "Error in opening the file." << endl;
        exit(1);
    }
    while (fin2.eof() == 0)
    {
        fin2.getline(temp, 256);
        cout << temp << endl;
    }
    fin2.close();

    cout << "\nReading with while !eof loop." << endl;
    ifstream fin3("1file1.txt");
    if (!fin3)
    {
        cout << "Error in opening the file." << endl;
        exit(1);
    }
    while (!fin3.eof())
    {
        fin3.getline(temp, 256);
        cout << temp << endl;
    }
    fin3.close();

    cout << "\nReading character by character." << endl;
    char ch;
    ifstream fin4("1file1.txt");
    if (!fin4)
    {
        cout << "Error in opening the file." << endl;
        exit(1);
    }
    while (fin4)
    {
        fin4.get(ch);
        cout << ch;
    }
    fin4.close();
}