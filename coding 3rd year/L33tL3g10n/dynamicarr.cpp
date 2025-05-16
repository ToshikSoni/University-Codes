#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int *arr;
    arr = new int[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    for (int i = 0; i < 5; i++)
        cout << arr[i] << ' ';
    cout<<endl;

    int *temparr;
    temparr = new int[5];
    for (int i = 0; i < 5; i++)
        temparr[i] = arr[i];
    for (int i = 0; i < 5; i++)
        cout << temparr[i] << ' ';

    delete arr;
    arr = new int[10];
    for (int i = 0; i < 5; i++)
        arr[i] = temparr[i];
    delete temparr;

    arr[5] = 6;
    arr[6] = 7;
    arr[7] = 8;
    arr[8] = 9;
    arr[9] = 10;

    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';
}