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
    void iterative_Postorder(Node *);
    void recursive_Postorder(Node *);
    Node *createNode(int);
};

void Traversal::iterative_Postorder(Node *p)
{
    stack<long int> stk;
    long int temp;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            stk.emplace((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = stk.top();
            stk.pop();
            if (temp > 0)
            {
                stk.emplace(-temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

void Traversal::recursive_Postorder(Node *p)
{
    if (p)
    {
        cout << p->data;
        recursive_Postorder(p->lchild);
        recursive_Postorder(p->rchild);
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
    cout << "Postorder Traversal is by iteration is: ";
    t.iterative_Postorder(root);
    cout << "Inorder Trversal is by recusrion is: ";
    t.recursive_Postorder(root);
    return 0;
}