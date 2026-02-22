#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int solve(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    int count = 0;

    for (int i = 1; i <= 6; i++)
    {
        count = (count + solve(n - i, dp)) % mod;
    }
    return dp[n] = count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << solve(n, dp) << "\n";
}