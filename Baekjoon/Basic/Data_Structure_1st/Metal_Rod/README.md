10799번 쇠막대기
-------------

'('는 긴 쇠막대기를 하나 더 늘리고, ')'는 긴 쇠막대기를 하나 줄이고 쇠막대기의 갯수를 하나 늘린다.  
예외적인 경우는 '(' 다음에 ')'이 오는 경우인데, 이 땐 긴 쇠막대기의 갯수만큼 전체 쇠막대기 갯수를 늘려야한다.  
Stack을 이용할 경우에 입력하는 괄호의 배열이 ')'가 먼저 오는 경우, 즉 Stack이 비어있을 때 Pop이 오는 경우가 존재하지 않음으로 따로 예외 처리를 해 줄 필요는 없다.

~~~ cpp
#include <cstdio>

#define MAX 100001

int countRod(char* input) {
    int rod = 0;
    int result = 0;

    for ( int i = 0; i < MAX; i++ ) {
        if ( input[i] == '(' ) {
            if ( input[i + 1] == ')' ) {
                result += rod;
                i++;
            } else {
                rod++;
            }
        } else if ( input[i] == ')' ) {
            result++;
            rod--;
        } else {
            break;
        }
    } 

    return result;
}

int main() {
    char input[MAX];
    scanf("%s", input);

    printf("%d\n", countRod(input));

    return 0;
}
~~~