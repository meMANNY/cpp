#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_VAL = 1000000;
vector<int> spf(MAX_VAL + 1); // Smallest prime factor

// Function to precompute the smallest prime factor for each number
void computeSPF()
{
    for (int i = 1; i <= MAX_VAL; ++i)
        spf[i] = i; // Initialize with the number itself
    for (int i = 2; i * i <= MAX_VAL; ++i)
    {
        if (spf[i] == i)
        { // i is prime
            for (int j = i * i; j <= MAX_VAL; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// Segment tree implementation
class SegmentTree
{
private:
    vector<long long> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return;
        if (start == end)
        {
            int d = spf[arr[start]];
            arr[start] /= d;
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r);
        update(2 * node + 1, mid + 1, end, l, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return 0;
        if (start >= l && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }

    void pointUpdate(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            arr[start] = val;
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
        {
            pointUpdate(2 * node, start, mid, idx, val);
        }
        else
        {
            pointUpdate(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SegmentTree(vector<int> &inputArr)
    {
        n = inputArr.size();
        arr = inputArr;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void rangeUpdate(int l, int r) { update(1, 0, n - 1, l, r); }
    long long rangeQuery(int l, int r) { return query(1, 0, n - 1, l, r); }
    void updatePoint(int idx, int val) { pointUpdate(1, 0, n - 1, idx, val); }
};

int main()
{
    computeSPF(); // Precompute smallest prime factors

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    vector<vector<int>> queries(Q, vector<int>(3));
    for (int i = 0; i < Q; ++i)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    SegmentTree segTree(a);
    vector<long long> results;

    for (const auto &query : queries)
    {
        int type = query[0];
        int l = query[1] - 1;
        int r = query[2] - 1;

        if (type == 1)
        {
            segTree.rangeUpdate(l, r);
        }
        else if (type == 2)
        {
            results.push_back(segTree.rangeQuery(l, r));
        }
        else if (type == 3)
        {
            segTree.updatePoint(l, query[2]);
        }
    }

    for (long long res : results)
    {
        cout << res << endl;
    }

    return 0;
}
