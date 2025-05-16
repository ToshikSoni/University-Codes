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
int depthNode(Node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->key == key)
        return 1;
    int left = depthNode(root->left, key);
    if (left != 0)
        return left + 1;
    int right = depthNode(root->right, key);
    if (right != 0)
        return right + 1;
    return 0;
}
int main()
{
    Node *root = buildTree();
    printPreOrder(root);
    cout << endl
         << "depth of node: " << depthNode(root, 5) - 1;
}