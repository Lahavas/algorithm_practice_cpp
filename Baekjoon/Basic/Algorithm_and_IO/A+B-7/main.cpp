#include <cstdio>

int main() {
    int tc;
    scanf("%d", &tc);

    for ( int i = 1; i <= tc; i++ ) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", i, a + b);
    }

    return 0;
}