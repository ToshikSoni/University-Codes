#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
int main()
{
    cout << "Randomly generated strings: " << endl;
    vector<char> arr(26, 0), ARR(26, 0);
    for (int i = 0; i < 26; i++)
        ARR[i] = i + 65;
    for (int i = 0; i < 26; i++)
        arr[i] = i + 97;
    vector<char> tempa, tempA;
    int size = 26;
    while (arr.size() != 0)
    {
        int temp = rand() % size;
        size--;
        swap(arr[temp], arr[size]);
        tempa.push_back(arr[size]);
        arr.pop_back();
    }
    size = 26;
    while (ARR.size() != 0)
    {
        int temp = rand() % size;
        size--;
        swap(ARR[temp], ARR[size]);
        tempA.push_back(ARR[size]);
        ARR.pop_back();
    }
    for (int i = 0; i < tempa.size(); i++)
        cout << char(i + 97) << ' ';
    cout << endl;
    for (int i = 0; i < tempa.size(); i++)
        cout << tempa[i] << ' ';
    cout << endl;
    cout << endl;
    for (int i = 0; i < tempa.size(); i++)
        cout << char(i + 65) << ' ';
    cout << endl;
    for (int i = 0; i < tempa.size(); i++)
        cout << tempA[i] << ' ';
    cout << endl;
    cout << endl;
    string str;
    cout << "Enter the string: ";
    getline(std::cin, str);
    for (int i = 0; i < str.length(); i++)
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
            continue;
        else if (str[i] >= 65 && str[i] <= 90)
            str[i] = tempA[str[i] - 65];
        else if (str[i] >= 97 && str[i] <= 122)
            str[i] = tempa[str[i] - 97];
    cout << "Converted string: " << str;
}