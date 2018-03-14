#include <iostream>
#include <string>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    string s;

    while ( getline(cin, s) ) {
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;

        int len = s.length();

        for ( int i = 0; i < len; i++ ) {
            if ( s[i] >= 'a' && s[i] <= 'z' ) {
                lower += 1;
            } else if ( s[i] >= 'A' && s[i] <= 'Z' ) {
                upper += 1;
            } else if ( s[i] >= '0' && s[i] <= '9' ) {
                number += 1;
            } else if ( s[i] == ' ' ) {
                space += 1;
            }
        }

        cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
    }

    return 0;
}