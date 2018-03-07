10820번 문자열 분석
----------------

입력받는 문자열 최대값은 문자 100자 + 문자열 마지막 NULL ('\0') 1자 + '\n' 1자 해서 총 102로 설정해야합니다.

1. fgets 함수 사용

~~~ cpp
#include <cstdio>
#include <cstring>

#define MAX 102

int main() {
    char s[MAX];

    while ( fgets(s, sizeof(s), stdin) != NULL ) {
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;

        int len = strlen(s);

        for ( int i = 0; i < len; i++ ) {
            if ( s[i] >= 'a' && s[i] <= 'z' ) {
                lower++;
            } else if ( s[i] >= 'A' && s[i] <= 'Z' ) {
                upper++;
            } else if ( s[i] >= '0' && s[i] <= '9' ) {
                number++;
            } else if ( s[i] == ' ' ) {
                space++;
            }
        }

        printf("%d %d %d %d\n", lower, upper, number, space);
    }

    return 0;
}
~~~

2. getline 함수 사용

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
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
                lower++;
            } else if ( s[i] >= 'A' && s[i] <= 'Z' ) {
                upper++;
            } else if ( s[i] >= '0' && s[i] <= '9' ) {
                number++;
            } else if ( s[i] == ' ' ) {
                space++;
            }
        }

        cout << lower << ' ' << upper << ' ' << number << ' ' << space << endl;
    }

    return 0;
}
~~~