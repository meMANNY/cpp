#include <bits/stdc++.h>
using namespace std;

int myceil(long long a, int b)
{
    if (a % b == 0)
        return (a / b);
    bool positive = !((a < 0) ^ (b < 0));
    return a / b + positive;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n, x;
        cin >> n >> x;
        long long sum = 0;
        long long maxi = 0;
        for (int i = 0; i < n; i++)
        {
            long long y;
            cin >> y;
            sum += y;
            maxi += myceil(y, x);
        }

        long long min = (sum + x - 1) / x; // Manually round up the division

        cout << min << " " << maxi << "\n";
    }
    return 0;
}
