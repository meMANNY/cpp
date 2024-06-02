#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findGcd(int a, int b)
    {
        while (a > 0 && b > 0)
        {
            if (a > b)
            {

                a = a % b;
            }

            else
            {

                b = b % a;
            }
        }

        if (a == 0)
        {
            return b;
        }

        return a;
    }
    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        // Path compression logic ....return parent[node] value instread of just a recursive call.
        return parent[node] = findParent(parent[node]);
    }
    void UnionSet(int u, int v)
    {

        u = findParent(u);
        v = findParent(v);

        if (rank[u] < rank[v] && findGcd(u, v) > 1)
        {
            parent[u] = v;
        }
        else if (rank[v] < rank[u] && findGcd(u, v) > 1)
        {

            parent[v] = u;
        }

        else if (rank[u] == rank[v] && findGcd(u, v) > 1)
        {
            parent[v] = u;
            rank[u]++;
        }
        else // if gcd is not greater than 1 then do nothing
        {
            return;
        }
    }
};
int main()
{
    DisjointSet ds(3);

    ds.UnionSet(3, 9);
    ds.UnionSet(9, 5);

    // if (ds.findParent(3) == ds.findParent(5))
    // {
    //     cout << "Same\n";
    // }
    // else
    //     cout << "Not same\n";

    cout << "hello";

    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    // if (ds.findParent(3) == ds.findParent(4)) {
    //     cout << "Same\n";
    // }
    // else cout << "Not same\n";

    // ds.UnionSet(3, 4);

    // if (ds.findParent(3) == ds.findParent(4)) {
    //     cout << "Same\n";
    // }
    // else cout << "Not same\n";
    return 0;
}