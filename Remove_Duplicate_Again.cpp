#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> integer_linkedList;
    int val;
    while (cin >> val && val != -1)
    {
        integer_linkedList.push_back(val);
    }

    integer_linkedList.sort();
    //remove duplicates
    integer_linkedList.unique();
    for (int val : integer_linkedList)
    {
        cout << val << " ";
    }

    return 0;
}
