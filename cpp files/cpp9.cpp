#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll ceil_div(long long a, long long b)
{
    return a / b + ((a ^ b) > 0 && a % b);
}
int main()
{
    ll t, n, i, j, ans, temp, sum;
    string sans;
    t = 1;
    cin >> t;
    while (t--)
    {
        sans = "NO";
        ans = temp = sum = 0;
        cin >> n;
        ll sum = 0;
        ll neg = 0;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            sum += x;
            if (x == -1)
                neg++;
        }

        ans = ceil_div(-sum, 2);
        if (sum >= 0)
            ans = 0;
        neg -= ans;
        if (neg & 1)
            ans++;
        cout << ans << "\n";
    }
    return 0;
}