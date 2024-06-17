#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
    vector<int> seg;

public:
    SegmentTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int query(int ind, int low, int high, int l, int r)
    {

        if (r < low || l > high)
        {
            return INT_MAX;
        }
        if (l <= low && r >= high)
        {
            return seg[ind];
        }

        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, high, l, r);
        int right = query(2 * ind + 2, low, high, l, r);

        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (i < low || i > high)
        {
            return;
        }
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, i, val);
        update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

// void solve()
// {
//     int n;
//     cin >> n;
//     int arr[n];

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     int seg[4 * n];
//     build(0, 0, n - 1, arr,seg);

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int type;
//         cin >> type;
//         if (type == 1)
//         {
//             int l, r;
//             cin >> l >> r;
//             cout << query(0, 0, n - 1, l, r, seg) << endl;
//         }
//         else
//         {
//             int i, val;
//             cin >> i >> val;
//             update(0, 0, n - 1, i, val, seg);
//             arr[i] = val;
//         }
//     }
// }
void solve2()
{
    int n1;
    cin >> n1;
    int arr[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr[i];
    }
    SegmentTree st1(n1);
    st1.build(0, 0, n1 - 1, arr);
    int n2;
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    SegmentTree st2(n2);
    st2.build(0, 0, n2 - 1, arr2);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l1, r1, l2, r2;

            cin >> l1 >> r1 >> l2 >> r2;
            int mini1 = st1.query(0, 0, n1 - 1, l1, r1);
            int mini2 = st2.query(0, 0, n2 - 1, l2, r2);

            cout << min(mini1, mini2) << endl;
        }
        else
        {
            int arrNo, ind, val;
            cin >> arrNo >> ind >> val;

            if (arrNo == 1)
            {
                st1.update(0, 0, n1 - 1, ind, val);
                arr[ind] = val;
            }
            else
            {
                st2.update(0, 0, n2 - 1, ind, val);
                arr2[ind] = val;
            }
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve2();
    return 0;
}