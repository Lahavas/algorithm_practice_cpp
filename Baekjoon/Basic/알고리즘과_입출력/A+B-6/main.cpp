#include <cstdio>

int main() {
    int cnt = 0;
    scanf("%d", &cnt);

    while ( cnt-- ) {
        int a = 0, b = 0;
        scanf("%d,%d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}