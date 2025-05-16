#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    string key;
    T value;
    Node *next;
    Node(string k, T dat)
    {
        key = k;
        next = NULL;
        value = dat;
    }
    int count()
    {
        int count = 1;
        Node *temp = this;
        while (temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
template <typename T>
class HashTable
{
    Node<T> **table;
    int cs, ts;
    int HashFn(string key)
    {
        int idx = 0, power = 1;
        for (auto ch : key)
        {
            idx = (idx + (ch * power)) % ts;
            power = (power * 19) % ts;
        }
        return idx;
    }
    void rehash()
    {
        Node<T> **oldTable = table;
        int oldTs = ts;
        cs = 0;
        ts = ts * 2 + 1;
        table = new Node<T> *[ts];
        for (int i = 0; i < ts; i++)
            table[i] = NULL;
        for (int i = 0; i < oldTs; i++)
        {
            Node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;
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
        cs = n->count();
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
                    table[idx] = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        return;
    }
};