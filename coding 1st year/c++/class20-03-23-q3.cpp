#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("1file3.txt");
    if (!fout)
    {
        cout << "Error in opening the file." << endl;
        exit(1);
    }
    fout << "hello world\n";
    fout << "how are you wasfa, I am fine thank you";
    cout << "Location of pointer :" << fout.tellp();
    fout.seekp(5, ios::beg);
    fout << "hi";
    fout.close();
}