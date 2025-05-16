#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("file.txt");
    fout << "hello";
    fout.close();
    ifstream fin("file.txt");
    string temp;
    getline(fin,temp);
    cout << temp;
    fin.close();
}