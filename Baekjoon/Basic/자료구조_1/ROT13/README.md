11655번 ROT13
-------------

1. fgets 함수 사용

~~~ cpp
#include <cstdio>
#include <cstring>

constexpr int MAX = 101;

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
    char s[MAX] = { '\0' };
    fgets(s, sizeof(s), stdin);

    int len = strlen(s);

    for ( int i = 0; i < len; ++i ) {
        s[i] = rot13(s[i]);
    }

    printf("%s\n", s);

    return 0;
}
~~~

2. getline 함수 사용

~~~ cpp
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
~~~