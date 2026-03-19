#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<long long> a(n), p(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {

        p[i + 1] = p[i] + a[i];
    }

    long long ans = 0;

    for (int i = 0; i <= k; i++)
    {

        int left_idx = 2 * i;
        int right_idx = n - (k - i);

        long long curr_sum = p[right_idx] - p[left_idx];
        ans = max(ans, curr_sum);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        solve();
    }
    return 0;
}