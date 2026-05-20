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

        vector<long long> v(n);

        for (int i = 0; i < n; i++)
        {

            cin >> v[i];
        }

        long long ans = -1;

        long long x = 2;

        while (x <= (1LL << 57))
        {

            set<long long> s;

            for (int i = 0; i < n; i++)
            {

                s.insert(v[i] % x);
            }

            if (s.size() == 2)
            {

                ans = x;

                break;
            }

            x *= 2;
        }

        cout << ans << '\n';
    }

    return 0;
}