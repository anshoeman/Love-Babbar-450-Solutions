#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class Traversal
{
private:
    Node *root;

public:
    void iterative_inorder(Node *);
    void recursive_inorder(Node *);
    Node *createNode(int);
};

void Traversal::iterative_inorder(Node *root)
{
    stack<Node *> s; /*creating a stack to store address*/
    while (root != NULL || !s.empty())
    {
        /*open 2 cases*/
        if (root!=nullptr)
        {
            s.push(root);
            root = root->lchild;
        }
        else
        {
            root = s.top();
            cout << root->data <<","<<flush; /*this should print the data*/
            s.pop();
            root = root->rchild; /*move towards right child*/
        }
    }
}

void Traversal::recursive_inorder(Node *p)
{
    if (p)
    {
        cout << p->data;
        recursive_inorder(p->lchild);
        recursive_inorder(p->rchild);
    }
}

Node *Traversal::createNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;

    return (node);
}

int main(void)
{
    Traversal t;
    Node *root = t.createNode(1);
    root->lchild = t.createNode(2);
    root->rchild = t.createNode(3);
    root->lchild->lchild = t.createNode(4);
    root->lchild->rchild = t.createNode(5);
    cout << "Inorder Traversal is by iteration is: ";
    t.iterative_inorder(root);
    return 0;
}