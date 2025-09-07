#include <bits/stdc++.h>
using namespace std;

int getMinPath(vector<int> coins, int tree_nodes,
               vector<int> tree_from, vector<int> tree_to)
{
    int n = tree_nodes;
    vector<vector<int>> adj(n);
    for (int i = 0; i < (int)tree_from.size(); i++)
    {
        int u = tree_from[i], v = tree_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(n, -1), depth(n, 0);
    queue<int> q;
    q.push(0);
    parent[0] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (parent[v] == -1)
            {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
    vector<int> coin_nodes;
    for (int i = 0; i < n; i++)
        if (coins[i])
            coin_nodes.push_back(i);
    sort(coin_nodes.begin(), coin_nodes.end(),
         [&](int a, int b)
         { return depth[a] > depth[b]; });
    vector<char> covered(n, 0), is_center(n, 0);
    vector<int> mark(n, 0);
    int mark_id = 1;
    for (int u : coin_nodes)
    {
        if (covered[u])
            continue;
        int c = u;
        if (depth[c] >= 2)
            c = parent[parent[c]];
        else if (depth[c] == 1)
            c = parent[c];
        is_center[c] = 1;
        queue<pair<int, int>> qq;
        qq.push({c, 0});
        ++mark_id;
        mark[c] = mark_id;
        while (!qq.empty())
        {
            int x = qq.front().first;
            int d = qq.front().second;
            qq.pop();
            if (coins[x])
                covered[x] = 1;
            if (d == 2)
                continue;
            for (int y : adj[x])
            {
                if (mark[y] != mark_id)
                {
                    mark[y] = mark_id;
                    qq.push({y, d + 1});
                }
            }
        }
    }
    int total_centers = accumulate(is_center.begin(), is_center.end(), 0);
    if (total_centers == 0)
        return 0;
    vector<int> subcnt(n, 0);
    function<int(int, int)> dfs = [&](int u, int p)
    {
        int cnt = is_center[u];
        for (int v : adj[u])
            if (v != p)
                cnt += dfs(v, u);
        return subcnt[u] = cnt;
    };
    dfs(0, -1);
    int edges = 0;
    for (int i = 1; i < n; i++)
    {
        if (subcnt[i] > 0 && subcnt[i] < total_centers)
            edges++;
    }
    return edges * 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // next line in custom input is “n (again)  and  n-1”
    int nodes, m;
    cin >> nodes >> m; // nodes == n, m == n-1

    vector<int> tree_from(m), tree_to(m);
    // read the from-array
    for (int i = 0; i < m; i++)
        cin >> tree_from[i];
    // read the to-array
    for (int i = 0; i < m; i++)
        cin >> tree_to[i];

    cout << getMinPath(coins, nodes, tree_from, tree_to) << "\n";
    return 0;
}