10820번 문자열 분석
----------------

입력받는 문자열 최대값은 문자 100자 + 문자열 마지막 NULL ('\0') 1자 + '\n' 1자 해서 총 102로 설정해야합니다.

~~~ cpp
#include <cstdio>
#include <cstring>

#define MAX 102

int main() {
    char input[MAX];

    while ( fgets(input, sizeof(input), stdin) != NULL ) {
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;

        for ( int i = 0; i < strlen(input); i++ ) {
            if ( input[i] >= 'a' && input[i] <= 'z' ) {
                lower++;
            } else if ( input[i] >= 'A' && input[i] <= 'Z' ) {
                upper++;
            } else if ( input[i] >= '0' && input[i] <= '9' ) {
                number++;
            } else if ( input[i] == ' ' ) {
                space++;
            }
        }

        printf("%d %d %d %d\n", lower, upper, number, space);
    }

    return 0;
}
~~~