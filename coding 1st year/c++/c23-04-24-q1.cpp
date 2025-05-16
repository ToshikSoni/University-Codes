#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
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
void printInOrder(Node *root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << root->key << " ";
    printInOrder(root->right);
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
int calcHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int left = calcHeight(root->left);
    int right = calcHeight(root->right);
    int maxDepth = max(left, right) + 1;
    return maxDepth;
}
int countNodes(Node *root, int n)
{
    if (root)
    {
        n = n + 1;
        n = countNodes(root->left, n);
        n = countNodes(root->right, n);
    }
    return n;
}
int countLeafNodes(Node *root, int n)
{
    if (root)
    {
        if (root->left == NULL && root->right == NULL)
            return n + 1;
        n = countLeafNodes(root->left, n);
        n = countLeafNodes(root->right, n);
    }
    return n;
}
int countFullNodes(Node *root, int n)
{
    if (root)
    {
        if (root->left && root->right)
        {
            cout << root->key << " " << endl;
            n++;
        }
        n = countFullNodes(root->left, n);
        n = countFullNodes(root->right, n);
    }
    return n;
}
int main()
{
    Node *root = new Node(1);
    insert(root, 3);
    insert(root, 2);
    insert(root, 5);
    insert(root, 7);
    insert(root, 4);
    insert(root, 10);
    printInOrder(root);
    cout << endl;
    search(root, 10);
    cout << endl
         << "Height: " << calcHeight(root);
}