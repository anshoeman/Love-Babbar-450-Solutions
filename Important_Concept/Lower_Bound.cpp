/*
lower_bound MAP STL
*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> mp;
    mp.insert(pair<int, int>(1, 20));
    mp.insert(pair<int, int>(2, 30));
    mp.insert(pair<int, int>(3, 50));
    mp.insert(pair<int, int>(5, 50));

    auto it = mp.lower_bound(4);/*throws lower bound*/
    cout << (*it).first << '\t' << (*it).second;

    return 0;
}
