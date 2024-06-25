#include <iostream>
#include <vector>
using namespace std;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;

        cin >> n >> k;
        vector<int> ch(26, 0);

        for (int i = 0; i < n; i++)
        {
            char ct;
            cin >> ct;
            ch[ct - 'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {

            if (ch[i] % 2 == 1)
                cnt++;
            // cout << i << " " << cnt << "\n";
        }

        if (cnt > k + 1)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }

    return 0;
}