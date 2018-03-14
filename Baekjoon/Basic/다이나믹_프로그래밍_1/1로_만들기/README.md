1463번 1로 만들기
--------------

D[N]은 N을 1로 만드는 데 필요한 연산의 최솟값이라고 정의할 수 있습니다.  
조건이 세 가지 방법 중에 최소값을 구하는 방법이므로, D[N] = min(D[N/3]+1, D[N/2]+1, D[N-1]+1) 이라고 할 수 있습니다.

1. Top-down 방식으로 풀이

~~~cpp
#include <cstdio>

constexpr int MAX = 1000001;

int d[MAX] = { 0 };

int solve(int n) 
{
    if ( n == 1 ) {
        return 0;
    }

    if ( d[n] > 0 ) {
        return d[n];
    }

    d[n] = solve(n - 1) + 1;

    if ( n % 2 == 0 ) {
        int temp = solve(n / 2) + 1;
        if ( d[n] > temp ) {
            d[n] = temp;
        }
    }

    if ( n % 3 == 0 ) {
        int temp = solve(n / 3) + 1;
        if ( d[n] > temp ) {
            d[n] = temp;
        }
    }

    return d[n];
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

constexpr int MAX = 1000001;

int d[MAX] = { 0 };

int main() 
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        if ( i == 1 ) {
            d[i] = 0;
            continue;
        }

        d[i] = d[i - 1] + 1;

        if ( i % 2 == 0 && d[i] > d[i / 2] + 1 ) {
            d[i] = d[i / 2] + 1;
        }

        if ( i % 3 == 0 && d[i] > d[i / 3] + 1 ) {
            d[i] = d[i / 3] + 1;
        }
    }

    int result = d[n];

    printf("%d\n", result);

    return 0;
}
~~~