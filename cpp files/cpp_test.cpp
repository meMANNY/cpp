#include <bits/stdc++.h>
using namespace std;

int solve(long long m, vector<pair<int, int>> &b, int current_idx)
{
    int n = b.size();
    int count = current_idx;

    for (int i = current_idx + 1; i < n; i++)
    {
        if (m >= b[i].first)
        {
            m += b[i].first;
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
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

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        vector<long long> freq(n);
        freq[0] = a[0].first;
        for (int i = 1; i < n; i++)
        {
            freq[i] = freq[i - 1] + a[i].first;
        }

        vector<int> final_ans(n);
        for (int i = 0; i < n; i++)
        {
            int result = solve(freq[i], a, i);
            final_ans[a[i].second] = result;
        }

        for (int i = 0; i < n; i++)
        {
            cout << final_ans[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}