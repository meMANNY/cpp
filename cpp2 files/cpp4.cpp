#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        if (n == 2)
        {
            cout << 2 << "\n";
            continue;
        }
        for (ll i = 1; i < n; i++)
        {
            if (n % i != 0)
            {
                cout << i - 1 << "\n";
                break;
            }
        }
    }
    return 0;
}