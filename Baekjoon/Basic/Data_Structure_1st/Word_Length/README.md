2743번 단어 길이 재기
-----------------

~~~ cpp
#include <cstdio>

#define MAX 102

int main() {
    char input[MAX];
    scanf("%s", input);

    int length = 0;
    for ( int i = 0; i < MAX; i++ ) {
        if ( input[i] == '\0' ) {
            break;
        }
        length++;
    }
    
    printf("%d\n", length);

    return 0;
}
~~~