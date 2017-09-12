#include <cstdio>

int main() {
    int cnt;
    scanf("%d", &cnt);

    for ( int i = 1; i <= cnt; i++ ) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
    }

    return 0;
}