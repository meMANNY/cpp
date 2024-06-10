#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> choices(3, -1);
        for (int i = 0; i < 3; i++)
        {
            cin >> choices[i];
        }

        if (choices[2] % 2 == 0)
        {
            if (choices[0] > choices[1])
                cout << "First" << "\n";
            else
                cout << "Second" << "\n";
        }
        else
        {
            if (choices[1] > choices[0])
            {
                cout << "Second" << "\n";
            }
            else
                cout << "First" << "\n";
        }
    }

    return 0;
}