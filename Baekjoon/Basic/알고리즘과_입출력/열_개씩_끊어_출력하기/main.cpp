#include <iostream>
#include <string>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int cnt = 10;

    for ( int i = 0; i < s.size(); ++i ) {
        --cnt;
        cout << s[i];

        if ( cnt == 0 ) {
            cnt = 10;
            cout << '\n';
        }
    }

    return 0;
}