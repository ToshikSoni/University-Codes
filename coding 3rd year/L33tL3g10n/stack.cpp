#include <iostream>
using namespace std;
class Stack
{
public:
    int arr[10];
    int curr = -1;
    void push(int ele)
    {
        arr[++curr] = ele;
    }
    int pop()
    {
        if (curr != -1)
        {
            int temp = arr[curr];
            curr--;
            return temp;
        }
        return -1;
    }
    int top()
    {
        return arr[curr];
    }
    int size()
    {
        return curr;
    }
};
int main()
{
    Stack s;
    s.push(10);
    cout << s.top() << endl;
    s.push(20);
    cout << s.pop() << endl;
    cout << s.top() << endl;
    s.push(30);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.size() << endl;
}