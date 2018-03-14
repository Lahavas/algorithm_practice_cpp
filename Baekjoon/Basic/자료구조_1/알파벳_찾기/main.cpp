#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    for ( int i = 'a' ; i <= 'z'; ++i ) {
        auto it = find(s.begin(), s.end(), i);
    
        if ( it == s.end() ) {
            cout << -1 << ' ';
        } else {
            cout << (it - s.begin()) << ' ';
        }
    }

    cout << '\n';

    return 0;
}