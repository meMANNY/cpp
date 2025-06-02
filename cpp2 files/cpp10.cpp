#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int> &nums)
{
    int operations = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        while (nums[i] > nums[i - 1])
        {
            if (nums[i] == 1)
            {
                return -1; // Array cannot be made non-decreasing
            }

            // Find the greatest proper divisor efficiently
            int divisor = nums[i] / 2;
            while (nums[i] % divisor != 0)
            {
                divisor--;
            }

            nums[i] /= divisor;
            operations++;
        }
    }

    return operations;
}

int main()
{
    vector<int> nums = {3, 2, 4, 5, 0};
    int result = minOperations(nums);
    cout << "Minimum operations: " << result << endl;
    return 0;
}