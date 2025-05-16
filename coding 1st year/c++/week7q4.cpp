#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *left, *right;
    Node(int d)
    {
        key = d;
        left = right = NULL;
    }
};
Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
void search(Node *root, int key)
{
    static int count = 0;
    if (root->key == key)
    {
        cout << "Found " << key << " in tree at level: " << count << endl;
        return;
    }
    if (key > root->key)
    {
        count++;
        search(root->right, key);
    }
    else
    {
        count++;
        search(root->left, key);
    }
}
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node *remove(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }
    return root;
}
