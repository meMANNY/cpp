
#include <bits/stdc++.h>
using namespace std;
long long t;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;

        if ((n % 2 == 1) || n < 4)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << (n + 5) / 6 << ' ' << (n / 4) << '\n';
        }
    }
    return 0;
}