#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{

    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("abc", 2);

    m.insert(p);

    // 2

    pair<string, int> q("def", 3);
    m.insert(q);

    // 3
    m["ghi"] = 4;

    return 0;
}