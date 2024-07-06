#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int cnt = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 0)
            {
                cnt++;
            }
        }
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                start = i;
                break;
            }
        }
        for (int j = n - 1; j >= 0; j--)
        {
            if (arr[j] != 0)
            {
                end = j;
                break;
            }
        }
        bool flag = -1;
        if (cnt == n)
        {
            cout << 0 << "\n";
            continue;
        }
        for (int i = start; i <= end; i++)
        {
            if (arr[i] == 0)
            {
                cout << 2 << "\n";
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
        }

        if (flag == 0 && cnt != n)
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}