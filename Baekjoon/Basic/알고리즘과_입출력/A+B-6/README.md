10953번 A+B - 6
--------------

입력 받을 시에 ','를 구분자로 사용합니다.  
format string으로 입력받아야 하므로 cstdio를 사용하여 풀 수 있습니다.

1. cstdio 사용

~~~ cpp
#include <cstdio>

int main() {
    int tc;
    scanf("%d", &tc);

    while ( tc-- ) {
        int a, b;
        scanf("%d,%d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}
~~~