#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Memoization table
map<tuple<int, int, int>, int> memo;

// Function to count ways to partition N into K groups
int countWays(int remaining_sum, int remaining_groups, int last_used) {
    // Check the memoization table
    auto key = make_tuple(remaining_sum, remaining_groups, last_used);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    // Base cases
    if (remaining_groups == 0) {
        return remaining_sum == 0 ? 1 : 0;
    }
    if (remaining_sum < 0) {
        return 0;
    }

    // Recursive case
    int ways = 0;
    for (int next_value = last_used; next_value <= remaining_sum; ++next_value) {
        ways += countWays(remaining_sum - next_value, remaining_groups - 1, next_value);
    }

    // Save result in the memoization table
    memo[key] = ways;
    return ways;
}

int countPartitions(int N, int K) {
    return countWays(N, K, 1);
}

int main() {
    int N = 9;
    int K = 5;
    cout << "Number of ways to partition " << N << " into " << K << " groups: " << countPartitions(N, K) << endl;
    return 0;
}
