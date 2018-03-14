9095번 1, 2, 3 더하기
-------------------

D[N]은 N을 1, 2, 3의 조합으로 나타내는 방법의 수입니다.  
마지막의 수가 1이 온다면 D[N-1], 2가 온다면 D[N-2], 3이 온다면 D[N-3]이 와야하므로,  
D[N] = D[N-1] + D[N-2] + D[N-3] 이라고 할 수 있습니다.

1. Top-down 방식으로 풀이

~~~cpp
#include <cstdio>

constexpr int MAX = 11;

int d[MAX] = { 0 };

int solve(int n)
{
    if ( n == 1 ) {
        return 1;
    } else if ( n == 2 ) {
        return 2;
    } else if ( n == 3 ) {
        return 4;
    } else {
        if ( d[n] > 0 ) {
            return d[n];
        }

        d[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);

        return d[n];
    }
}

int main()
{
    int cnt = 0;
    scanf("%d", &cnt);

    while ( cnt-- ) {
        int n = 0;
        scanf("%d", &n);
        
        int result = solve(n);
        printf("%d\n", result);
    }

    return 0;
}
~~~

2. Bottom-up 방식으로 풀이  

~~~ cpp
#include <cstdio>

constexpr int MAX = 11;

int d[MAX] = { 0 };

int main()
{
    int cnt = 0;
    scanf("%d", &cnt);

    while ( cnt-- ) {
        int n = 0;
        scanf("%d", &n);

        for ( int i = 1; i <= n; ++i ) {
            if ( i == 1 ) {
                d[i] = 1;
            } else if ( i == 2 ) {
                d[i] = 2;
            } else if ( i == 3 ) {
                d[i] = 4;
            } else {
                d[i] = d[i - 1] + d[i - 2] + d[i - 3];
            }
        }
        
        int result = d[n];
        printf("%d\n", result);
    }

    return 0;
}
~~~