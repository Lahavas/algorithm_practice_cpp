#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> v;

    for ( int i = 0; i < s.size(); ++i ) {
        v.push_back(i);
    }

    sort(v.begin(), v.end(), [&s] (const int u, const int v) {
        return strcmp(s.c_str() + u, s.c_str() + v) < 0;
    });

    for ( auto x : v ) {
        cout << s.substr(x) << '\n';
    }

    return 0;
}