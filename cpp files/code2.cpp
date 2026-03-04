#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        int ans = p[0], sum = p[0];
        int mini_so_far = min(0, p[0]);

        for (int i = 1; i < n; i++)
        {

            if (abs(p[i] % 2) == abs(p[i - 1] % 2))
            {
                mini_so_far = 0;
                sum = 0;
            }

            sum += p[i];
            ans = max(ans, sum - mini_so_far);
            mini_so_far = min(mini_so_far, sum);
        }

        cout << ans << "\n";
    }
    // test1
}