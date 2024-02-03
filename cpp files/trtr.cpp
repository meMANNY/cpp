#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// Function to calculate the Euclidean distance between two points
double euclideanDistance(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to check if the jump is feasible
bool isFeasibleJump(Point p1, Point p2, int X)
{
    return euclideanDistance(p1, p2) == X;
}

// Function to determine if Kady can reach the destination and find the minimum number of jumps
void canReachDestination(Point S, Point R, int X)
{
    // Check if the jump from S to R is feasible
    if (!isFeasibleJump(S, R, X))
    {
        cout << "Kady cannot reach his destination." << endl;
        return;
    }

    double distance = euclideanDistance(S, R);
    int jumps = distance / X;

    cout << "Kady can reach his destination in " << jumps << " jumps." << endl;
}

int main()
{
    // Input variables
    int m, n, X, p, q, u, v;
    cout << "Enter the dimensions of the 2D plane (m n): ";
    cin >> m >> n;
    cout << "Enter Kady's favorite number X: ";
    cin >> X;
    cout << "Enter Kady's current position (p q): ";
    cin >> p >> q;
    cout << "Enter the destination position (u v): ";
    cin >> u >> v;

    // Check if Kady is within the plane
    if (p < 1 || p > m || q < 1 || q > n || u < 1 || u > m || v < 1 || v > n)
    {

        return 0;
    }
}
// Create Point objects for Kady's current position and the destination
