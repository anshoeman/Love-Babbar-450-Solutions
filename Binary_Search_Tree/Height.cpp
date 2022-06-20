/*
levelorder traversal can help us to find the height of the traversal
*/
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    Node *rchild;
    int data;
    Node *lchild;
};

class Tree
{
private:
    Node *root;

public:
    int height(Node *root);
};

int Tree::height(Node *root)
{
    int depth = 0;
    queue<Node *> q;
    int depth = 0;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp==NULL){
            depth++;/*traverse through the depth*/
        }
        if(temp!=NULL){
            
        }
    }
}