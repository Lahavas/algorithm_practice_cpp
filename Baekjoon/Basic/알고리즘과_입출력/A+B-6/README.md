10953번 A+B - 6
--------------

입력 받을 시에 ','를 구분자로 사용합니다.  
format string으로 입력받아야 하므로 cstdio header의 scanf 함수를 사용하여 풀 수 있습니다.

1. cstdio header의 scanf Function을 사용하여 Format String을 입력

~~~ cpp
#include <cstdio>

int main() 
{
    int cnt = 0;
    scanf("%d", &cnt);

    while ( cnt-- ) {
        int a = 0, b = 0;
        scanf("%d, %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}
~~~