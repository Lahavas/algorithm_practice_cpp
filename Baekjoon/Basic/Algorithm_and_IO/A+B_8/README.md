11022번 A+B - 8
--------------

출력 시에 문자열 "Case #"을 추가하여야합니다. 또한 case별로 index값을 붙여야 하기 때문에 for문이 적합하다고 생각합니다.  
format string으로 입력받는 것이 더 편리하므로 cstdio를 사용하는 쪽을 추천합니다.

1. cstdio 사용

~~~ cpp
#include <cstdio>

int main() {
    int test_case;
    scanf("%d", &test_case);

    for ( int i = 1; i <= test_case; i++ ) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
    }

    return 0;
}
~~~