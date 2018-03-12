11022번 A+B - 8
--------------

출력 시에 문자열 "Case #"을 추가하여야합니다. 또한 case별로 index값을 붙여야 하기 때문에 for문을 사용하는것이 적합합니다.  
format string으로 입력받는 것이 더 편리하므로 cstdio header의 scanf 함수를 사용해야합니다.

1. cstdio header의 scanf Function을 사용하여 Format String을 입력

~~~ cpp
#include <cstdio>

int main() 
{
    int cnt = 0;
    scanf("%d", &cnt);

    for ( int i = 1; i <= cnt; ++i ) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
    }

    return 0;
}
~~~