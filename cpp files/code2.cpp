#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);

        //test
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int left = 0;
        int right = q;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int cnt = 0;

            for (int i = 0; i < n; i++)
            {

                if (a[i] < mid)
                {
                    cnt += (mid - a[i]);
                }
            }

            if (cnt < q)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << right << endl;
        cout << "\n";
    }
    return 0;
}