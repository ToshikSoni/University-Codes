#include <iostream>
#include <queue>
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
void printPreOrder(Node *root) // from root to leftmost to rightmost
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void printInOrder(Node *root) // from left most node to root to rightmost
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << root->key << " ";
    printInOrder(root->right);
}
void printPostOrder(Node *root) // from leftmost to rightmost to root
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->key << " ";
}
Node *buildLevelOrderTree()
{
    int d, c1, c2;
    cout << "Enter root value: ";
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << "\nCurrent node: " << current->key << endl;
        cout << "Enter child nodes value: ";
        cin >> c1;
        cin >> c2;
        if (c1 == -1)
            current->left = NULL;
        else
        {
            current->left = new Node(c1);
            Q.push(current->left);
        }
        if (c2 == -1)
            current->right = NULL;
        else
        {
            current->right = new Node(c2);
            Q.push(current->right);
        }
        Q.pop();
    }
    return root;
}
void LevelOrderPrint(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->key << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}
int countNode(Node *root)
{
    static int count = 0;
    if (root == NULL)
        return 0;
    count++;
    countNode(root->left);
    countNode(root->right);
    return count;
}
int countLeaf(Node *root)
{
    static int count = 0;
    if (root == NULL)
        return 0;
    if (root->right == NULL && root->left == NULL)
        count++;
    countLeaf(root->left);
    countLeaf(root->right);

    return count;
}
int countFull(Node *root)
{
    static int count = 0;
    if (root == NULL)
        return 0;
    if (root->right != NULL && root->left != NULL)
        count++;
    countFull(root->left);
    countFull(root->right);

    return count;
}
int main()
{
    // Node *root = buildTree();
    // printPreOrder(root);
    // cout << endl;
    // printPostOrder(root);
    // cout << endl;
    // printInOrder(root);
    // cout << endl;
    Node *root = buildLevelOrderTree();
    printPreOrder(root);
    cout << endl;
    cout << "Nodes: " << countFull(root);
}