#include <bits/stdc++.h>
using namespace std;
vector<int> print_divisors(int n)
{
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                divisors.push_back(i);
            else
            {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> k = print_divisors(n);

        long long maxi = 0;
        for (int idx : k)
        {

            if (idx == n)
                continue;

            long long maxi_sum = -1;
            long long mini_sum = -1;

            for (int i = 0; i < n; i += idx)
            {
                long long curr_sum = 0;

                for (int j = i; j < i + idx; j++)
                {
                    curr_sum += a[j];
                }
                if (maxi_sum == -1 || curr_sum > maxi_sum)
                {
                    maxi_sum = curr_sum;
                }
                if (mini_sum == -1 || curr_sum < mini_sum)
                {
                    mini_sum = curr_sum;
                }
            }

            maxi = max(maxi, maxi_sum - mini_sum);
        }
        cout << maxi;
        cout << "\n";
    }
    return 0;
}