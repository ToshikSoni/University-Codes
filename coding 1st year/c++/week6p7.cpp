#include <iostream>
#include <fstream>
using namespace std;
int main()
{
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