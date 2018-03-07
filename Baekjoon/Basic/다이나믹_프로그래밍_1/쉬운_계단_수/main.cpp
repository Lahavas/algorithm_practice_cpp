#include <cstdio>

#define MAX 101
#define DIVIDE 1000000000

long d[MAX][10] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    for ( int i = 1; i <= 9; i++ ) {
        d[1][i] = 1;
    }

    for ( int i = 2; i <= n; ++i ) {
        for ( int j = 0; j <= 9; ++j ) {
            if ( j == 0 ) {
                d[i][j] = d[i - 1][1];
            } else if ( j == 9 ) {
                d[i][j] = d[i - 1][8];
            } else {
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
            }

            d[i][j] %= DIVIDE;
        }
    }
    
    long result = 0;
    for ( int i = 0; i <= 9; ++i ) {
        result += d[n][i];
        result %= DIVIDE;
    }

    printf("%ld\n", result);
    
    return 0;
}