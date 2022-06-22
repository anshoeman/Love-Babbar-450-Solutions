/*
map STL will be used in the vertical order
*/
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main()
{
    /*empty map will be created*/
    map<int, int> m;
    m.insert(pair<int, int>(1, 40));
    m.insert(pair<int, int>(2, 40));
    m.insert(pair<int, int>(3, 40));
    m[7] = 70;
    map<int, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr)
    {
        cout << itr->first << '\t' << itr->second;
    }
    /*map the values into another map STL*/
    map<int, int> m2(m.begin(), m.end()); /*mapped values*/
    /*remove all elements with key = 4*/
    int num;
    for (int i = 0; i < 2; i++)
    {
        num = m2.erase(i);/*remove the key*/
    }

    cout << "Remove element";
    for (itr = m2.begin(); itr != m2.end(); ++itr)
    {
        cout << itr->first << '\t' << itr->second;
    }
    /*lower bound and upper bound*/
    
}