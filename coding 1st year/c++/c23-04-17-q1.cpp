#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    string key;
    T value;
    Node *next;

    Node()
    {
        next = NULL;
    }
    Node(string k, T dat) // constructor to initalize the values
    {
        key = k;
        next = NULL;
        value = dat;
    }
    void connectData(Node *n) // passing next value to connect two nodes
    {
        next = n;
    }
    void insertData(Node *n1, Node *n2) // passing previous and next nodes to insert value between them
    {
        n1->next = this;
        next = n2;
    }
    void deleteData(Node *n) // passing previous node to change its address to next node
    {
        n->next = next;
        delete (this);
    }
    friend void search(Node *n, string k) // passing head to let the loop access all the nodes one after another by accessing address from the pointer
    {
        int count = 0;
        Node *temp = n;
        while (true)
        {
            count++;
            if (k == temp->key)
            {
                cout << "Key found in trials: " << count << endl;
                break;
            }
            else
                temp = temp->next;
        }
    }
    friend void sort(Node *n) // bubble sort
    {
        Node *temp1, *temp2;
        int tempint;
        bool temp = true;
        while (temp == true)
        {
            temp = false;
            temp1 = n;
            while (temp1->next != NULL)
            {
                temp2 = temp1->next;
                if (temp1->value > temp2->value)
                {
                    tempint = temp1->value;
                    temp1->value = temp2->value;
                    temp2->value = tempint;
                    temp = true;
                }
                temp1 = temp1->next;
            }
        }
    }
    void show() // show function to show value address and next value
    {
        cout << "Key: " << key << "\nValue: " << value << "\nptr: " << next << "\nthis: " << this << endl
             << endl;
    }
    friend void showHead(Node *n)
    {
        Node *temp = n;
        while (temp != NULL)
        {
            temp->show();
            temp = temp->next;
        }
    }
};
template <typename T>
class HashTable
{
    Node<T> **table;
    int cs; // countsize of the items inserted into the table
    int ts; // tablesize of entries the table
    // hash function
    int HashFn(string key)
    {
        int idx = 0;
        int power = 1;
        for (auto ch : key)
        {
            idx = (idx + (ch * power)) % ts;
            power = (power * 29) % ts;
        }
        return idx;
    }
    void rehash()
    {
        // making a pointer to the old table
        Node<T> **oldTable = table;
        int oldTs = ts;
        // increasing the table size
        cs = 0;
        ts = ts * 2 + 1;
        table = new Node<T> *[ts];
        for (int i = 0; i < ts; i++)
            table[i] = NULL;
        // copying elements from old table to new table
        for (int i = 0; i < oldTs; i++)
        {
            Node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;
                // happen in the new table
                insert(key, value);
                temp = temp->next;
            }
            if (oldTable[i] != NULL)
                delete oldTable[i];
        }
        delete[] oldTable;
    }

public:
    HashTable(int default_size = 7)
    {
        cs = 0;
        ts = default_size;
        table = new Node<T> *[ts];
        for (int i = 0; i < ts; i++)
            table[i] = NULL;
    }
    void insert(string key, T value)
    {
        int idx = HashFn(key);
        Node<T> *n = new Node<T>(key, value);
        n->next = table[idx];
        table[idx] = n;
        cs++;
        // reshashing
        float load_factor = cs / (float)ts;
        if (load_factor > 0.7)
            rehash();
    }
    T *search(string key)
    {
        int idx = HashFn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
                return &temp->value;
            temp = temp->next;
        }
        return NULL;
    }
    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << "Bucket " << i << " -> ";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void erase(string key)
    {
        int idx = HashFn(key);
        Node<T> *temp = table[idx];
        if (temp == NULL)
            cout << "There is nothing to delete" << endl;
        Node<T> *prev = NULL;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                if (prev == NULL)
                {
                    table[idx] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        return;
    }
};
int main()
{
    HashTable<int> h;
    h.insert("Mango", 100);
    h.insert("Apple", 120);
    h.insert("Banana", 140);
    h.insert("Orange", 200);
    h.print();
    string fruit;
    cout << "Enter the fruit to be searched: ";
    cin >> fruit;
    int *price = h.search(fruit);
    if (price != NULL)
        cout << "The price of " << fruit << " is: " << *price << endl;
    else
        cout << "Fruit is not present." << endl;
}