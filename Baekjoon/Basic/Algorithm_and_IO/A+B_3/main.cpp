#include <cstdio>

int main(void) 
{
    int cnt;
    scanf("%d", &cnt);

    while (cnt--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}