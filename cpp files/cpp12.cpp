#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 1;
        int ans = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i + 1] != s[i])
                cnt = 1;
            else
                cnt++;
            ans = max(ans, cnt);
        }
        cout << ans + 1 << "\n";
    }
}
