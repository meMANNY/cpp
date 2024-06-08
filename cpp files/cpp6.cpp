#include <iostream>
#include <vector>
using namespace std;

vector<int> constructSequence(const vector<int> &b)
{
    vector<int> a;
    a.push_back(b[0]); // Start with the first element of b in a
    for (size_t i = 1; i < b.size(); ++i)
    {
        // Add a value less than the current element of b to ensure ai-1 <= ai
        a.push_back(b[i] - 1);
        // Then add the current element of b
        a.push_back(b[i]);
    }
    return a;
}

int main()
{
    vector<int> b = {4, 6, 3}; // Example sequence
    vector<int> a = constructSequence(b);

    for (int num : a)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
