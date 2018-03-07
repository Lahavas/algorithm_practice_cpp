#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> vt;

    int size = s.size();

    for ( int i = 0; i < size; i++ ) {
        vt.push_back(i);
    }

    sort(vt.begin(), vt.end(), [&s] (int u, int v) {
        return strcmp(s.c_str() + u, s.c_str() + v) < 0;
    });

    for ( auto &x : vt ) {
        cout << s.substr(x) << endl;
    }

    return 0;
}