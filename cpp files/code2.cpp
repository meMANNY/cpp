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

        for (int i = 1; i < n - 1; i++)
        {
            if (p[i - 1] < p[i] && p[i] > p[i + 1])
            {
                swap(p[i], p[i + 1]);
            }
        }
        int flag = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (p[i] > p[i + 1])
            {
                flag++;
            }
        }

        if (flag == 0)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}