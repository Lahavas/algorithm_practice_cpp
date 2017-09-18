11655번 ROT13
-------------

1. fgets 함수 사용

~~~ cpp
#include <cstdio>
#include <cstring>

#define MAX 102

char ROT13(char c) {
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

int main() {
    char s[MAX];
    fgets(s, sizeof(s), stdin);

    int len = strlen(s);

    for ( int i = 0; i < len; i++ ) {
        s[i] = ROT13(s[i]);
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

char ROT13(char c) {
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

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);

    int len = s.length();

    for ( int i = 0; i < len; i++ ) {
        s[i] = ROT13(s[i]);
    }

    cout << s << endl;

    return 0;
}
~~~