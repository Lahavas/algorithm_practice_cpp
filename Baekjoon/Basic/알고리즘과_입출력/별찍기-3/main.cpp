#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 0; i < n; ++i ) {
        for ( int j = n; j > i; --j ) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}