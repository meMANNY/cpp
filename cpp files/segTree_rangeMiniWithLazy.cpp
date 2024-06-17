#include <bits/stdc++.h>
using namespace std;

class SegTreeMin
{
    vector<int> seg, lazy;

public:
    SegTreeMin(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

public:
    void build(int ind, int high, int low, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, mid, low, arr);
        build(2 * ind + 2, high, mid + 1, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int ind, int low, int high, int l, int r, int val)
    {
        // update the previous remaining updates and propogate downwords.
        if (lazy[ind] != 0)
        {
            seg[ind] += lazy[ind];
            // proprogate the lazy update downwards
            // for the remaining nodes to get updated.

            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap
        // just return

        if (r < low || l > high)
            return;

        // complete overlap

        if (low >= l && high <= r)
        {
            seg[ind] += val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        // partial overlap

        int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int query(int ind, int low, int high, int l, int r)
    {
        // update if any updates are remaining as the node willl stay fresh and updated
        if (lazy[ind] != 0)
        {
            seg[ind] += lazy[ind];
            // proprogate the lazy update downwards
            // for the remaining nodes to get updated.

            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // no overlap
        if (high < l | r < low)
            return INT_MAX;

        // complete overlap

        if (low >= l && high <= r)
            return seg[ind];
        // partial overlap

        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegTreeMin st(n);
    st.build(0, n - 1, 0, arr);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(0, 0, n - 1, l, r) << endl;
        }
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            st.update(0, 0, n - 1, l, r, val);
        }
    }

    return 0;
}