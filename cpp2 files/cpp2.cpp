#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string findSmallestPalindromicSubsequence(const string &s)
{
    int n = s.size();
    vector<vector<string>> dp(n, vector<string>(n));

    // Base case: Single characters are palindromes
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = s[i];
    }

    // Build the DP table
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;

            if (s[i] == s[j])
            {
                dp[i][j] = s[i] + dp[i + 1][j - 1] + s[j];
            }
            else
            {
                string option1 = dp[i + 1][j];
                string option2 = dp[i][j - 1];
                if (option1.size() == option2.size())
                {
                    dp[i][j] = min(option1, option2);
                }
                else
                {
                    dp[i][j] = (option1.size() < option2.size()) ? option1 : option2;
                }
            }
        }
    }

    string result = dp[0][n - 1];
    return result.empty() ? "-1" : result;
}

int main()
{
    string s;
    cin >> s;

    string result = findSmallestPalindromicSubsequence(s);
    cout << result << endl;

    return 0;
}