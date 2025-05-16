#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string temp;
    cout << "Enter plain text: ";
    getline(cin, temp);
    int pad[temp.length()];
    for (int i = 0; i < temp.length(); i++)
    {
        pad[i] = rand() % 10;
        temp[i] ^= pad[i];
    }
    cout << endl
         << "Cipher text: " << endl;
    for (auto x : temp)
        cout << x << ' ';
    cout << endl
         << "Pad: " << endl;
    for (auto x : pad)
        cout << x << ' ';
    for (int i = 0; i < temp.length(); i++)
        temp[i] ^= pad[i];
    cout << endl
         << endl
         << "Decrypted text: " << temp << endl;
}