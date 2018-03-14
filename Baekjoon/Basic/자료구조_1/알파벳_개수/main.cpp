#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    for ( int i = 'a'; i <= 'z'; ++i ) {
        cout << count(s.begin(), s.end(), i) << ' ';
    }

    cout << '\n';

    return 0;
}