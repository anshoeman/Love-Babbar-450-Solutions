#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Tree
{
private:
    Node *root;

public:
    Tree();
    void createTree();
    void LevelOrder(Node *);
};

Tree::Tree()
{
    root = nullptr;
}

void Tree::createTree()
{
    int x;
    Node *p;
    Node *t;
    queue<Node *> q;
    root = new Node;

    cout << "Enter the root node: ";
    cin >> x;

    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.push(root); /*Q.PUSH(ROOT) we have to push the root*/
    while (!q.empty())
    {
        p = q.front();
        q.pop(); /*pop the address*/
        cout << "Enter Left child of" << p->data << ":"<<flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node; /*make the node for left child*/
            t->data = x;
            t->rchild = nullptr;
            t->lchild = nullptr;
            p->lchild = t;
            q.push(t); /*push the address of the freshly created node*/
        }

        cout << "Enter right child of" << p->data << ":"<<flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node; /*make the node for left child*/
            t->data = x;
            t->rchild = nullptr;
            t->lchild = nullptr;
            p->rchild = t;
            q.push(t); /*push the address of the freshly created node*/
        }
    }
}

void Tree::LevelOrder(Node *p)
{
    /*construct a queue and a stack*/
    queue<Node *> q;
    stack<int> s;
    q.push(p); /*just enter the value of p*/
    while (!q.empty())
    {
        p = q.front();
        q.pop(); /*pop the address*/
        s.push(root->data);
        if (p->lchild)
        {
            s.push(p->lchild->data);
            q.push(p->lchild);
        }
        else
        {
            s.push(p->rchild->data);
            q.push(p->rchild);
        }
    }
    cout << "enter";
    while (!s.empty())
    {
        int p = s.top();
        cout << p;
        s.pop();
    }

    cout << "Executed";
}

int main(void)
{
    Tree bt;
    Node *root;
    bt.createTree();
    bt.LevelOrder(root);
    return 0;
}