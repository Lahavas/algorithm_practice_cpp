10808번 알파벳 개수
----------------

문자열과 문자에 대한 이해가 필요한 문제입니다.

~~~ cpp
#include <cstdio>
#include <cstring>

#define MAX 100

int main() {
    char input[MAX];
    scanf("%s", input);

    for ( int i = 'a'; i <= 'z'; i++) {
        int cnt = 0;

        for ( int j = 0; j < strlen(input); j++ ) {
            if ( i == input[j] ) {
                cnt++;
            }
        }

        printf("%d ", cnt);
    }

    printf("\n");

    return 0;
}
~~~