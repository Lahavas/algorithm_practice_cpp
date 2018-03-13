#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            if ( i <= j ) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}