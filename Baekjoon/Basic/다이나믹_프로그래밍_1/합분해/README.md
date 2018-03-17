2225번 합분해
-----------

D[K][N]은 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수로 정의할 수 있습니다.  
D[K][N] = D[K-1][N] + D[K-1][N-1] + ... + D[K-1][0] 이라고 할 수 있습니다.  

~~~ cpp
#include <iostream>

using namespace std;

constexpr long mod = 1000000000;
constexpr int SIZE = 201;

long long d[SIZE][SIZE] = { 0 };

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0, k = 0;
    cin >> n >> k;
    
    d[0][0] = 1;
    
    for ( int i = 1; i <= k; ++i ) {
        for ( int j = 0; j <= n; ++j ) {
            for ( int l = 0; l <= j; ++l ) {
                d[i][j] += d[i - 1][j - l];
                d[i][j] %= mod;
            }
        }
    }
    
    cout << d[k][n] << '\n';
    
    return 0;
}
~~~