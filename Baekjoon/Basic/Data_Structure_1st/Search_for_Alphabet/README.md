10809번 알파벳 찾기
----------------

문자열에서의 인덱스를 출력하는 문제입니다.

~~~ cpp
#include <cstdio>
#include <cstring>

#define MAX 100

int main() {
    char input[MAX];
    scanf("%s", input);

    for ( int i = 'a' ; i <= 'z'; i++ ) {
        int index = -1;

        for ( int j = 0; j < strlen(input); j++ ) {
            if ( i == input[j] ) {
                index = j;
                break;
            }
        }
        
        printf("%d ", index);
    }

    printf("\n");

    return 0;
}
~~~