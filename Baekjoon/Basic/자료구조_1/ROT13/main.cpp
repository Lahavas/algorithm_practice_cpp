#include <iostream>
#include <string>

using namespace std;

char rot13(char c) 
{
    if ( c >= 'a' && c <= 'm' ) {
        return c + 13;
    } else if ( c >= 'n' && c <= 'z' ) {
        return c - 13;
    } else if ( c >= 'A' && c <= 'M' ) {
        return c + 13;
    } else if ( c >= 'N' && c <= 'Z' ) {
        return c - 13;
    } else {
        return c;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);

    for ( auto &c : s ) {
        c = rot13(c);
    }

    cout << s << '\n';

    return 0;
}