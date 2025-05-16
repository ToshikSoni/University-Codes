#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream file;
    string c = "hiiii";
    file.open("file", ios::out | ios::binary);
    file.write((char *)&c, sizeof(c));
    file.close();
    file.open("file", ios::in | ios::binary);
    string ch;
    file.read((char *)&ch, sizeof(c));
    file.close();
    cout << ch;
}