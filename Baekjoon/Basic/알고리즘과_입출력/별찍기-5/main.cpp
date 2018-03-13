#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= n; ++j ) {
            if ( i + j <= n ) {
                putchar(' ');
            } else {
                for ( int k = 1; k <= (i * 2) - 1; ++k ) {
                    putchar('*');
                }
                break;
            }
        }
        putchar('\n');
    }

    return 0;
}