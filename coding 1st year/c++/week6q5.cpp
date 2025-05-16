#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("file.txt");
    fout << "hello my name is toshik soni" << endl;
    cout << "Current position of the pointer is: " << fout.tellp() << endl;
    fout.seekp(5, ios::beg);
    fout << " Hello ";
    fout.close();
    ifstream fin("file.txt");
    string temp;
    getline(fin, temp);
    cout << temp << endl;
    cout << "Current position of the pointer is: " << fin.tellg() << endl;
    fin.seekg(5, ios::beg);
    getline(fin, temp);
    cout << temp << endl;
    fin.close();
}