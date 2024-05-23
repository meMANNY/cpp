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

    // searching
    cout << m["abc"] << endl;

    // size
    cout << m.size() << endl;

    // to check presence
    cout << m.count("abc") << endl;

    // erase
    cout << m.erase("abc") << endl;

    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    return 0;
}