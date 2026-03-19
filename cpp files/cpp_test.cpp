#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;

string reverse_cyclic_shift(string &s, long long k)
{

    long long n = s.size();
    string temp = s;
    rotate(temp.rbegin(), temp.rbegin() + 1, temp.rend());
    return temp;
}

vector<long long> nextSmallerElement(vector<long long> &arr, long long n)
{
    stack<long long> s;
    s.push(-1);
    vector<long long> ans(n);
    for (long long i = n - 1; i >= 0; i--)
    {

        while (s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<long long> prevSmallerElement(vector<long long> &arr, long long n)
{
    stack<long long> s;
    s.push(-1);
    vector<long long> ans(n);
    for (long long i = 0; i < n; i++)
    {

        while (s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<long long> &heights)
{
    int n = heights.size();
    vector<long long> next(n);

    next = nextSmallerElement(heights, n);
    vector<long long> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
            next[i] = n;
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<long long> height(matrix[0].size(), 0);
    int maxi = INT_MIN;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < height.size(); j++)
        {
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }

        maxi = max(maxi, largestRectangleArea(height));
    }

    return maxi;
}

void solve()
{
    string s;
    cin >> s;

    long long n = s.size();
    vector<vector<char>> matrix(n, vector<char>(n));
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            matrix[i][j] = s[j];
        }
        s = reverse_cyclic_shift(s, i + 1);
    }

    cout << maximalRectangle(matrix) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    while (n--)
    {
        solve();
    }
    return 0;
}