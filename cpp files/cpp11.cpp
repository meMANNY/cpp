#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> gcd;
        int x;
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            int y;
            cin >> y;
            gcd.push_back(y);
        }
        int flag = 0;
        for (int i = 0; i < gcd.size(); i++)
        {
            for (int j = 0; j < gcd.size(); j++)
            {
                if (__gcd(gcd[i], gcd[j]) <= 2 && i != j)
                {
                    flag = 1;
                    break;
                }
                else
                    continue;
            }
        }
        if (flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}