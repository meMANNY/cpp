#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;

    vector<long long> a(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {

        cin >> p[i];
    }

    long long start = -1;
    long long end = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != p[i])
        {
            end = i;
            if (start == -1)
            {
                start = i;
            }
        }
    }

    while (start > 0 && p[start - 1] <= p[start])
    {
        start--;
    }
    while (end < n - 1 && p[end] <= p[end + 1])
    {
        end++;
    }

    cout << start + 1 << " " << end + 1 << "\n";
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