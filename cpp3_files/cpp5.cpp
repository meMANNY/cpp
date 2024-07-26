#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0)
    {

        int n;
        cin >> n;

        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mpp[x]++;
        }
        int maxi = 0;
        for (auto it = mpp.begin(); it != mpp.end(); ++it)
        {
            auto &entry = *it;
            int x = entry.first;
            int y = entry.second;
            maxi = max(maxi, y);
        }

        int ans = 0;
        while (maxi < n)
        {

            int d = min(n - maxi, maxi);
            ans += 1 + d;
            maxi += d;
        }
        cout << ans << "\n";
    }
    return 0;
}