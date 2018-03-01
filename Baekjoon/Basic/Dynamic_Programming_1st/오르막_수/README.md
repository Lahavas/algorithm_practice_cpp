11057번 오르막 수
--------------

~~~ cpp
#include <cstdio>

#define MAX 1001
#define DIVIDE 10007

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
            for ( int k = j; k <= 9; ++k ) {
                d[i][j] += d[i - 1][k];
                d[i][j] %= DIVIDE;
            }
        }
    }
    
    int result = 0;
    for ( int i = 0; i <= 9; ++i ) {
        result += d[n][i];
        result %= DIVIDE;
    }
    
    printf("%d\n", result);
    
    return 0;
}
~~~