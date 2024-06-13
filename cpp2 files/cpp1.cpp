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
        int x;
        cin >> x;
        int cnt = 0;
        vector<int> arr(x);
        for (int i = 0; i < x; i++)
        {
            cin >> arr[i];
            if (arr[i] == 2)
                cnt++;
        }

        if (cnt % 2 != 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            int half = cnt / 2;
            int diff = 0;
            for (int i = 0; i < x; i++)
            {
                if (arr[i] == 2)
                    diff++;
                if (diff == half)
                {
                    cout << i + 1 << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}