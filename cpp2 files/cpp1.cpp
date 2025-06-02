#include <bits/stdc++.h>
using namespace std;

vector<int> computeDistances(int n, int en, vector<vector<int>> &tree)
{
    vector<int> distance(n + 1, -1);
    queue<int> q;
    q.push(en);
    distance[en] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbor : tree[node])
        {
            if (distance[neighbor] == -1)
            {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return distance;
}

vector<int> generateCheeseOrder(int n, int st, int en, vector<vector<int>> &tree)
{
    vector<int> distance = computeDistances(n, en, tree);
    vector<int> vertices(n);
    iota(vertices.begin(), vertices.end(), 1);

    sort(vertices.begin(), vertices.end(), [&](int a, int b)
         { return distance[a] > distance[b]; });

    return vertices;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, st, en;
        cin >> n >> st >> en;

        vector<vector<int>> tree(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<int> result = generateCheeseOrder(n, st, en, tree);

        if (result.empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            for (int num : result)
            {
                cout << num << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}