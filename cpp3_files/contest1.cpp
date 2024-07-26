#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
    {
        int n, x;
        cin >> n >> x;

        int size = n / x;

        vector<vector<int>> ans(size, vector<int>(size, 0));
        for (int i = 0; i < n; i++)
        {
            string row;
            cin >> row;
            for (int j = 0; j < n; j++)
            {
                int value = row[j] - '0';

                if (i % x == 0 && j % x == 0)
                {
                    ans[i / x][j / x] = value;
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
