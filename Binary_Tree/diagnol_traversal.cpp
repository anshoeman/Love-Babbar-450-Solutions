/*
we shall use maps
root and root->right are prioritized over root->left
iterative method
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};

/*return the vector of the traversed*/
vector<int> diagonal(node *root)
{
    vector<int> diagnolvalues; /*these are the diagnol values*/
    if (!root)
        return diagnolvalues;
    queue<node *> leftqueue;
    node *node = root;
    while(node){
        
    }
}
