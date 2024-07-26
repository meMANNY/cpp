#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxSumOfRopePairLengths(vector<int> &ropes)
{
    // Sort the ropes in descending order

    long long sum = 0;

    // Pair the ropes from the largest to the smallest
    for (int i = 0; i < ropes.size() - 1; i += 2)
    {
        int a = ropes[i];
        int b = ropes[i + 1];
        // Calculate the number of valid intersection points for this pair
        sum += (a - 1) * (b - 1);
    }

    return sum;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> ropes(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> ropes[i];
        }

        cout << maxSumOfRopePairLengths(ropes) << endl;
    }

    return 0;
}