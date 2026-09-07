#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define nl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    vi A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int i = 0;
    int j = 0;
    int sum = 0;

    int len = -1;

    while (j < n)
    {
        sum += A[j];
        if (sum > s)
        {
            sum -= A[i];
            i++;
        }
        if (sum == s)
        {
            len = max(len, j - i + 1);
        }
        j++;
    }

    if (len == -1)
    {
        cout << len << nl;
    }
    else
    {
        cout << n - len << nl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}