#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
};

class Tree
{
private:
    Node *root;
public:
    Node *newNode(int);
    void printVericalOrder(Node *root);
};

void Tree::printVericalOrder(Node *root)
{
    if (!root)
        return;
    map<int, vector<int> > m;
    int hd = 0;
    queue<pair<Node *, int> > q;  /*pair for the node and int type */
    q.push(make_pair(root, hd)); /*push initial pair inside*/
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front(); /*take out the first pair*/
        q.pop();
        hd = temp.second;
        Node *node = temp.first;
        m[hd].push_back(node->data);
        if (node->left)
            q.push(make_pair(node->left, hd));
        if (node->right)
            q.push(make_pair(node->right, hd));
    }
    /*print the values*/
    map<int, vector<int> >::iterator it;
    /*iterate through the map*/
    for (it = m.begin(); it != m.end(); ++it)
    {
        for (int i = 0; i < it->second.size(); i++)
            cout << it->second[i]<<'\t';
        cout << endl;
    }
}
Node* Tree::newNode(int key){
    Node* node = new Node;
    node->data = key;
    node->left = node->right = NULL;
    return node;
}
int main(void){
    Tree t;
    Node* root = t.newNode(1);
    root->left = t.newNode(2);
    root->right = t.newNode(3);
    root->left->left = t.newNode(4);
    root->left->right = t.newNode(5);
    root->right->left = t.newNode(6);
    root->right->right = t.newNode(7);
    root->right->left->right = t.newNode(8);
    root->right->right->right = t.newNode(9);
    root->right->right->left = t.newNode(10);
    root->right->right->left->right = t.newNode(11);
    root->right->right->left->right->right = t.newNode(12);
    cout << "Vertical order traversal is \n"<<'\t';
    t.printVericalOrder(root);
    return 0;
}