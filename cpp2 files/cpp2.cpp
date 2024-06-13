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
        int n, a, b;
        cin >> n >> a >> b;
        if (n == a && a == b)
        {
            cout << "YES" << "\n";

            continue;
        }
        if (a + b + 2 <= n)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}