#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> linked_list;
    int Q;
    cin >> Q;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        if (X == 0)
        {
            linked_list.push_front(V);
        }
        else if (X == 1)
        {
            linked_list.push_back(V);
        }
        else if (X == 2)
        {
            if (V >= 0 && V < (int)linked_list.size())
            {
                auto it = linked_list.begin();
                for (int i = 0; i < V; i++)
                {
                    ++it;
                }
                linked_list.erase(it);
            }
        }
        // Print list l to right
        cout << "L -> ";
        for (auto it = linked_list.begin(); it != linked_list.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
        // r to left
        cout << "R -> ";
        for (auto it = linked_list.rbegin(); it != linked_list.rend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}
