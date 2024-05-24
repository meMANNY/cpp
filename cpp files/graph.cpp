#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

#include <list>

class graph
{
public:
    unordered_map<int, list<int>> m;

    void addEdge(int x, int y, bool direction)
    {
        // direction = 0->undirected
        // direction = 1->directed

        m[x].push_back(y);

        if (direction == 0)
        {
            m[y].push_back(x);
        }
    }

    void printAdjList()
    {
        for (auto p : m)
        {
            cout << p.first << "->";
            for (auto j : p.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main()
{

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "enter the number of edges: ";
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // create an undirected graph
        g.addEdge(u, v, 0);
    }

    // print graph
    g.printAdjList();
    return 0;
}
