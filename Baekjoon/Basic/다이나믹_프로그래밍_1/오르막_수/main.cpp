#include <cstdio>

constexpr int MAX = 1001;
constexpr int mod = 10007;

int d[MAX][10] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    for ( int i = 0; i <= 9; ++i ) {
        d[1][i] = 1;
    }
    
    for ( int i = 2; i <= n; ++i ) {
        for ( int j = 0; j <= 9; ++j ) {
            for ( int k = 0; k <= j; ++k ) {
                d[i][j] += d[i - 1][k];
                d[i][j] %= mod;
            }
        }
    }
    
    int res = 0;
    for ( int i = 0; i <= 9; ++i ) {
        res += d[n][i];
        res %= mod;
    }
    
    printf("%d\n", res);
    
    return 0;
}