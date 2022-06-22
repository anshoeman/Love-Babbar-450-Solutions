#include<iostream>
#include<map>
using namespace std;

int main() {
   // initialize container
    map<int, int> mp;
 
    // insert elements in random order
    mp.insert(pair<int,int>(1,20));
    mp.insert(pair<int,int>(2,30));
    mp.insert(pair<int,int>(3,30));
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " " <<
                              (*it).second << endl;
    }
   return 0;
}