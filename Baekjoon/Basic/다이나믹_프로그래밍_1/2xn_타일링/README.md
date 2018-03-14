11726번 2xn 타일링
----------------

D[N]은 2XN을 채우는 방법의 수라고 정의할 수 있습니다.  
N번째 열의 타일을 놓을 수 있는 방법은 두 가지입니다.  
첫 번째 방법인 2X1 타일을 놓는 경우엔 나머지 공간을 채우는 방법의 수가 D[N-1]이며,  
두 번째 방법인 1X2 타일을 놓는 경우엔 나머지 공간을 채우는 방법의 수가 D[N-2]입니다.  
따라서 D[N] = D[N-1] + D[N-2] 이라고 할 수 있습니다.

1. Top-down 방식으로 풀이

~~~ cpp
#include <cstdio>

constexpr int MAX = 1001;
constexpr int mod = 10007;

int d[MAX] = { 0 };

int solve(int n) 
{
    if ( n == 1 ) {
        return 1;
    } else if ( n == 2 ) {
        return 2;
    } else {
        if ( d[n] > 0 ) {
            return d[n];
        }
        
        d[n] = solve(n - 1) + solve(n - 2);
        d[n] %= mod;
        
        return d[n];
    }
}

int main() 
{
    int n = 0;
    scanf("%d", &n);

    int result = solve(n);
    printf("%d\n", result);

    return 0;
}
~~~

2. Bottom-up 방식으로 풀이

~~~ cpp
#include <cstdio>

constexpr int MAX = 1001;
constexpr int mod = 10007;

int d[MAX] = { 0 };

int main() 
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        if ( i == 1 ) {
            d[i] = 1;
        } else if ( i == 2 ) {
            d[i] = 2;
        } else {
            d[i] = d[i - 1] + d[i - 2];
        }

        d[i] %= mod;
    }

    int result = d[n];
    printf("%d\n", result);

    return 0;
}
~~~