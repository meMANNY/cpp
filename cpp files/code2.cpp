#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(__int128 num)
{
    __int128 sqrtNum = sqrtl(num);
    return (sqrtNum * sqrtNum == num);
}

// Custom input function for __int128
istream &operator>>(istream &in, __int128 &n)
{
    string s;
    in >> s;
    n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        n = n * 10 + (s[i] - '0');
    }
    return in;
}

// Custom output function for __int128
ostream &operator<<(ostream &out, const __int128 &n)
{
    if (n == 0)
    {
        out << 0;
        return out;
    }
    string s = "";
    __int128 num = n;
    if (num < 0)
    {
        out << '-';
        num = -num;
    }
    while (num > 0)
    {
        s += (num % 10) + '0';
        num /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}

void solve()
{
    __int128 sum = 0;
    __int128 n, c;
    __int128 Sqsum = 0;
    cin >> n >> c;
    int ar[n];
    for (__int128 i = 0; i < n; ++i)
    {
        cin >> ar[i];
        Sqsum += ar[i] * ar[i];
        sum += ar[i];
    }
    c -= Sqsum;
    c *= -1;
    // Using the quadratic formula to find integer solutions for x
    __int128 a = 4 * n;
    __int128 b = 4 * sum;
    __int128 discriminant = b * b - 4 * a * c;

    __int128 x1 = (-b + sqrtl(discriminant)) / (2 * a);
    __int128 x2 = (-b - sqrtl(discriminant)) / (2 * a);

    if (x1 >= 0)
        cout << x1 << "\n";
    else if (x2 >= 0)
        cout << x2 << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}