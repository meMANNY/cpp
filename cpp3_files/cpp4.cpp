#include <bits/stdc++.h>
using namespace std;
long long t;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        string first, second;
        cin >> first >> second;
        int size = second.size();
        vector<int> ans(size);

        int f_size = first.size();

        for (int i = 0; i < size; i++)
        {
            for (int j = f_size - 1; j >= 0; j--)
            {

                if (second[i] == first[j])
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < size - 1; i++)
        {

            if (ans[i] > ans[i + 1])
            {
                flag = false;
                cout << "NO" << endl;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}