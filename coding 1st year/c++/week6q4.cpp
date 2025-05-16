#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("file.txt");
    if (!fin)
    {
        cout << "File not opened.";
        exit(1);
    }
    string temp;
    while (!fin.eof())
    {
        getline(fin, temp);
        cout << temp << endl;
    }
    fin.close();
}