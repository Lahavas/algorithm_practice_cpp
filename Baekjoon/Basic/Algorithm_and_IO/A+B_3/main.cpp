#include <cstdio>

int main()  {
    int cnt;
    scanf("%d", &cnt);

    while ( cnt-- ) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}