#include <iostream>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(int a, int b)
    {
        return a > b; // This will create a max heap
    }
};

int main()
{
    // Create a max heap with a custom comparator
    priority_queue<int, vector<int>, Compare> pq;

    // Push some elements into the heap
    pq.push(1);
    pq.push(3);
    pq.push(2);

    // Print the top element of the heap
    cout << pq.top() << endl; // Output: 3

    // Pop the top element of the heap
    pq.pop();

    // Print the top element of the heap
    cout << pq.top() << endl; // Output: 2

    return 0;
}