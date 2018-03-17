#include <cstdio>

constexpr int MAX = 101;
constexpr long mod = 1000000000;

long d[MAX][10] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    for ( int i = 1; i <= 9; ++i ) {
        d[1][i] = 1;
    }

    for ( int i = 2; i <= n; ++i ) {
        for ( int j = 0; j <= 9; ++j ) {
            if ( j - 1 >= 0 ) {
                d[i][j] += d[i - 1][j - 1];
            }
            if ( j + 1 <= 9 ) {
                d[i][j] += d[i - 1][j + 1];
            }

            d[i][j] %= mod;
        }
    }
    
    long res = 0;
    for ( int i = 0; i <= 9; ++i ) {
        res += d[n][i];
        res %= mod;
    }

    printf("%ld\n", res);
    
    return 0;
}