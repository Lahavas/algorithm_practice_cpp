10844번 쉬운 계단 수
----------------

D[N][L]은 마지막 자리의 수가 L인 길이가 N인 계단 수의 갯수로 정의할 수 있습니다.  
1<=L<=8일 경우, D[N][L] = D[N-1][L-1] + D[N-1][L+1]라고 할 수 있습니다.  
L이 0일 경우, D[N][L] = D[N-1][L-1]이며,  
L이 9일 경우, D[N][L] = D[N-1][L+1]입니다.  

~~~ cpp
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
~~~