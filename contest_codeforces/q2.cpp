#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define nl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

void solve()
{
    int n;

    cin >> n;

    vector<int> a(n);

    for (auto &x : a)
        cin >> x;

    int c = 0;

    for (int i = 0; i < n - 1; i++)

    {

        //  a[j] = (i+j+2) / a[i]

        int x = a[i];

        for (int div = x; div < 2 * n; div += x)

        {

            int j = div - i - 2;

            if (j >= n)
            {
                break;
            }

            if (j < 0 || j <= i)
            {
                continue;
            }

            if (a[j] * a[i] == i + j + 2)
                c++;
        }
    }

    cout << c << endl;
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
// a test commit
//another test commit