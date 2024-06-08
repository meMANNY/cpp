#include <bits/stdc++.h>
using namespace std;
int main()
{

    int a;
    cin >> a;
    int mini = INT_MAX;
    for (int i = 0; i < a; i++)
    {
        int b;
        cin >> b;
        int diff = 0;
        if (b < 0)
            diff = (b * -1);
        else
            diff = b;
        mini = min(mini, diff);
    }
    cout << mini;

    return 0;
}