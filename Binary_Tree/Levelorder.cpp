/*what is level order
when we traverse the tree level by level....we call it as a level order
the data structure we will be using for solving thid will be a queue

Logic :
step - 1: check the address of the root node and make a pointer point on the root node
step - 2: check the left node and right node and push that into the queue
step - 3: now to traverse through the level order we can just take out the address of the left and rt(if they exist and make the p pointer point on them)
Repeat the same step
*/

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
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
    void LevelOrder(Node *p);
    void LevelOrder() { LevelOrder(root); }
};

Tree::Tree()
{
    root = nullptr; /*null pointer*/
}
/*create a tree*/
void Tree::createTree()
{
    Node *p;
    Node *t;
    int x;
    queue<Node*> q;
    /*create a root node*/
    root = new Node;
    cout << "Enter the root data";
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.push(root);
    while (!q.empty())
    {
        p = q.front(); /*get the root address*/
        q.pop();       /*we have to pop the address*/
        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.push(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.push(t);
        }
    }
}

void Tree::LevelOrder(Node *p)
{
    queue<Node*> q;
    vector<int> ans;
    cout << p->data << "," << flush; /*stores the values as permanent values in hardisk*/
    q.push(p);                    /*adds the element in the end*/
    while (!q.empty())               /*unless and untill queue is empty ie all the element has to be traversed*/
    {
        p = q.front(); /*address of the first element*/
        q.pop();/*remove the value from the queue*/
        if (p->lchild)
        {
            cout << p->lchild->data << "," << flush; /*p pointing on the root and then going to the lchild and then pointing at the data*/
            ans.push_back(p->lchild->data);/*answer is pushed in the vector*/
            q.push(p->lchild); /*push lchild in the queue*/
        }
        else
        {
            cout << p->rchild->data << "," << flush;
            ans.push_back(p->rchild->data);/*answer is pushed down in the following*/
            q.push(p->rchild); /*push right child in the queue*/
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]<<"ans";
    }
}

int main(void)
{
    Tree bt;
    Node *root;
    bt.createTree();
    cout << "LevelOrder" << endl;
    bt.LevelOrder();
    return 0;
}