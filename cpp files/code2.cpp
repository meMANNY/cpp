#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> x(q);

        for (int i = 0; i < q; i++)
        {
            cin >> x[i];
        }
        int min_q = 31;

        for (int i = 0; i < q; i++)
        {

            if (x[i] < min_q)
            {
                min_q = x[i];
            }
            else
            {
                continue;
            }

            long long divisor = 1LL << min_q;
            long long add = 1LL << (min_q - 1);

            for (int j = 0; j < n; j++)
            {
                if (a[j] % divisor == 0)
                {
                    a[j] += add;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}