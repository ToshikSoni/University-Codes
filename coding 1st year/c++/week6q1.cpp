#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("file.txt");
    fout << "hello";
    fout.close();
}