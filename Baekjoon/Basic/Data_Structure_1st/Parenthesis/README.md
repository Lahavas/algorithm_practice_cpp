9012번 괄호
---------

VPS (Valid Parenthesis String) 을 찾는 문제입니다.  
VPS가 성립하기 위해서는 문자열 내의 '(' 와 ')' 가 전부 대응되어야 합니다.  
주의할 점은, ')' 다음에 '(' 가 오면 안된다는 점입니다. 즉 순서 또한 고려해서 풀어야합니다.  
Stack을 이용해서 풀 게 되면, '('일 경우 Push를, ')'일 경우 Pop을 해주고, Stack이 비어있을 때 Pop이 오면 No를 출력하도록 설계하면 됩니다.  

~~~ cpp
#include <cstdio>

#define MAX 51

bool isValid(char* ps) {
    int cnt = 0;

    for ( int i = 0; i < MAX; i++ ) {
        if ( ps[i] == '(' ) {
            cnt++;
        } else if ( ps[i] == ')' ) {
            cnt--;
        } else {
            break;
        }

        if ( cnt < 0 ) {
            return false;
        }
    }

    return (cnt == 0 ? true : false);
}

int main() {
    int test_case;
    scanf("%d", &test_case);

    char ps[MAX];

    while ( test_case-- ) {
        scanf("%s", ps);

        if ( isValid(ps) == true ) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
~~~