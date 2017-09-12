#include <cstdio>

int main(void) 
{
    int cnt;
    scanf("%d", &cnt);

    for (int i = 1; i <= cnt; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", a, b, a + b);
    }

    return 0;
}