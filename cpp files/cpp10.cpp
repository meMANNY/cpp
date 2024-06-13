#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c, int d)
{

    if (a == c && c == d)
        return 0;
    int mini = INT_MAX;

    mini = min(1 + solve(a + 1, b + 1, c, d), 1 + solve(a - 1, b, c, d));
    return mini;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        int ans = 0;
        cin >> a >> b >> c >> d;
        ans = solve(a, b, c, d);
        cout << ans << "\n";
    }
    return 0;
}