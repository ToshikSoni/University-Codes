#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin;
    char temp[256];
    fin.open("1file3.txt");
    if (!fin)
    {
        cout << "Error in opening the file." << endl;
        exit(1);
    }
    fin >> temp;
    cout << temp << endl;
    cout << "Location of pointer :" << fin.tellg();
    fin.seekg(5, ios::cur);
    fin.getline(temp, 256);
    cout << endl
         << temp << endl;
    fin.close();
}