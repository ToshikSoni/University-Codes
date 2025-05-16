#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<char> temp;
    cout << "Alphabets: " << endl;
    for (int i = 0; i < 26; i++)
    {
        temp.push_back(65 + i);
        cout << temp[i] << ' ';
    }
    cout << endl;
    int count = 26;
    vector<char> sub;
    while (temp.size() != 0)
    {
        int tempint = rand() % count--;
        sub.push_back(temp[tempint]);
        swap(temp[tempint], temp[count]);
        temp.pop_back();
    }
    cout << "Subtituted alphabets: " << endl;
    for (int i = 0; i < sub.size(); i++)
        cout << sub[i] << ' ';
    for (int i = 0; i < 26; i++)
        temp.push_back(65 + i);
    cout << endl
         << endl
         << "Enter text: " << endl;
    string text;
    getline(cin, text);
    cout << "Cipher text: " << endl;
    string cipher = "";
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            cipher += ' ';
            continue;
        }
        cipher += sub[text[i] - 65];
    }
    cout << cipher;
}