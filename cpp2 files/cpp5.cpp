#include <bits/stdc++.h>

using namespace std;

int throwball(vector<int> &receiver, int seconds)
{
    int n = receiver.size();
    int curr = 0; // Start from the first receiver (0-based index)

    // Simulate the ball passing for each second
    for (int i = 0; i < seconds; i++)
    {
        curr = receiver[curr] - 1; // Move to the next receiver (1-based to 0-based index)
    }

    return curr + 1; // Return 1-based index of the final receiver
}

int main()
{
    int n;
    cin >> n; // Input number of receivers
    vector<int> receiver(n);

    // Input receiver positions
    for (int i = 0; i < n; i++)
    {
        cin >> receiver[i];
    }

    int seconds;
    cin >> seconds; // Input number of seconds

    // Output the final position of the ball
    cout << throwball(receiver, seconds) << endl;
    return 0;
}
