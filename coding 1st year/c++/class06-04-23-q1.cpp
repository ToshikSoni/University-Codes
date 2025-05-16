#include <iostream>
using namespace std;
class LinkedList
{
    int data;
    LinkedList *ptr;

public:
    LinkedList()
    {
        ptr = NULL;
    }
    LinkedList(int dat) // constructor to initalize the values
    {
        ptr = NULL;
        data = dat;
    }
    void connectData(LinkedList *n) // passing next value to connect two nodes
    {
        ptr = n;
    }
    void insertData(LinkedList *n1, LinkedList *n2) // passing previous and next nodes to insert data between them
    {
        n1->ptr = this;
        ptr = n2;
    }
    void deleteData(LinkedList *n) // passing previous node to change its address to next node
    {
        n->ptr = ptr;
        delete (this);
    }
    friend void search(LinkedList *n, int ele) // passing head to let the loop access all the nodes one after another by accessing address from the pointer
    {
        int count = 0;
        LinkedList *temp = n;
        while (true)
        {
            count++;
            if (ele == temp->data)
            {
                cout << "Element found in trials: " << count << endl;
                break;
            }
            else
                temp = temp->ptr;
        }
    }
    friend void sort(LinkedList *n) // bubble sort
    {
        LinkedList *temp1, *temp2;
        int tempint;
        bool temp = true;
        while (temp == true)
        {
            temp = false;
            temp1 = n;
            while (temp1->ptr != NULL)
            {
                temp2 = temp1->ptr;
                if (temp1->data > temp2->data)
                {
                    tempint = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = tempint;
                    temp = true;
                }
                temp1 = temp1->ptr;
            }
        }
    }
    void show() // show function to show data address and ptr value
    {
        cout << "Data: " << data << "\nptr: " << ptr << "\nthis: " << this << endl
             << endl;
    }
};
int main()
{
    LinkedList *head = new LinkedList(5);
    LinkedList *n2 = new LinkedList(8);
    LinkedList *n3 = new LinkedList(2);
    LinkedList *n4 = new LinkedList(15);
    LinkedList *n5 = new LinkedList(1);
    head->connectData(n2);
    n2->connectData(n3);
    n3->connectData(n4);
    n4->connectData(n5);
    sort(head);
    head->show();
    n2->show();
    n3->show();
    n4->show();
    n5->show();
}