11656번 접미사 배열
----------------

~~~ cpp
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string input;
    cin >> input;

    vector<int> vector;

    int size = input.size();

    for ( int i = 0; i < size; i++ ) {
        vector.push_back(i);
    }

    sort(vector.begin(), vector.end(), [&input] (int u, int v) {
        return strcmp(input.c_str() + u, input.c_str() + v) < 0;
    });

    for ( auto &x : vector ) {
        cout << input.substr(x) << endl;
    }

    return 0;
}
~~~