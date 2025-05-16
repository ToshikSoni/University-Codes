#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout << "Alphabets: " << endl;
    for (int i = 0; i < 26; i++)
        cout << char(i + 65) << ' ';
    vector<char> c1(26, 0), c2(26, 0);
    int k1 = 9, k2 = 14, temp = 0;
    for (int i = 0; i < 26; i++)
        if (i < 27 - k1)
            c1[i] = 'A' + k1 + i - 1;
        else
        {
            c1[i] = 'A' + temp;
            temp++;
        }
    temp = 0;
    for (int i = 0; i < 26; i++)
        if (i < 27 - k2)
            c2[i] = 'A' + k2 + i - 1;
        else
        {
            c2[i] = 'A' + temp;
            temp++;
        }
    cout << endl
         << "C1 is:" << endl;
    for (auto x : c1)
        cout << x << ' ';
    cout << endl
         << "C2 is:" << endl;
    for (auto x : c2)
        cout << x << ' ';
    string plain_text = "INDIAN PRESIDENT IS TRAVELLING THROUGH JAPAN IN AIR INDIA";
    vector<int> temparr;
    cout << endl
         << "Sequence is: ";
    for (int i = 0; i < plain_text.length(); i++)
        if (plain_text[i] != ' ')
        {
            int temp = rand() % 2;
            if (temp == 0)
            {
                cout << "C1, ";
                temparr.push_back(0);
            }
            else 
            {
                cout << "C2, ";
                temparr.push_back(1);
            }
        }
    temp = 0;
    for (int i = 0; i < plain_text.length(); i++)
        if (plain_text[i] != ' ')
        {
            if (temparr[temp] == 0)
                plain_text[i] = c1[plain_text[i] - 'A'];
            else
                plain_text[i] = c2[plain_text[i] - 'A'];
            temp++;
        }
    cout << endl
         << "Modified text: " << plain_text;
}