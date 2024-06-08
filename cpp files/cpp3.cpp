#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a;
        --a;
        int sum = 0;
        while (a--)
        {
            cin >> b;
            sum += b;
        }
        sum = -1 * sum;
        cout << sum << "\n";
    }
    return 0;
}