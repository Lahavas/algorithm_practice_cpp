11057번 오르막 수
--------------

D[N][L]은 마지막 자리 수가 L인 N자리 오르막 수로 정의할 수 있습니다.  
D[N][L] = D[N-1][0] + D[N-1][1] + ... + D[N-1][L] 이라고 할 수 있습니다.  

~~~ cpp
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
~~~