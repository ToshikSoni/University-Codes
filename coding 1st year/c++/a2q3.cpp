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
Node *buildTree()
{
    int d;
    cout << "Enter value: ";
    cin >> d;
    if (d == -1)
        return NULL;
    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
void printPreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
int treeHeight(Node *root)
{
    int temp1, temp2, count = 0;
    if (root == NULL)
        return 0;
    else
    {
        count++;
        temp1 = treeHeight(root->left);
        temp2 = treeHeight(root->right);
    }
    count += max(temp1, temp2);
    return count;
}
int main()
{
    Node *root = buildTree();
    printPreOrder(root);
    cout << endl
         << "Height of the tree is: " << treeHeight(root);
}