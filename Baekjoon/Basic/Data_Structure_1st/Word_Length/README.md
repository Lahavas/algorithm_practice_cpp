2743번 단어 길이 재기
-----------------

C언어의 문자열의 마지막은 NULL('\0')입니다.  
string이나 strlen을 사용할 수 없는 경우에는 해당 특성을 이용하여 문제를 풀 수 있습니다.  
strlen으로 문제를 풀 경우, strlen 함수의 시간 복잡도는 O(N) 이기 때문에, 반복문 내에서 strlen 함수 사용은 추천하지 않습니다.  

1. cstdio 사용

~~~ cpp
#include <cstdio>

#define MAX 102

int main() {
    char input[MAX];
    scanf("%s", input);

    int len = 0;
    for ( int i = 0; i < MAX; i++ ) {
        if ( input[i] == '\0' ) {
            break;
        }
        len++;
    }
    
    printf("%d\n", len);

    return 0;
}
~~~

2. cstring 사용

~~~ cpp
#include <cstdio>
#include <cstring>

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