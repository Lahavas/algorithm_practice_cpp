11727번 2xn 타일링 2
------------------

1. Top-down 방식으로 풀이

~~~ cpp
#include <cstdio>

#define MAX 1001
#define DIVIDE 10007

int arr[MAX] = { 0 };

int twoTimesN(int n)
{
    if ( n == 1 ) {
        return 1;
    } else if ( n == 2 ) {
        return 3;
    } else {
        if ( arr[n] > 0 ) {
            return arr[n];
        }
        
        arr[n] = twoTimesN(n - 1) + (twoTimesN(n - 2) * 2);
        
        if ( arr[n] > DIVIDE ) {
            arr[n] %= DIVIDE;
        }
        
        return arr[n];
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    int result = twoTimesN(n);
    printf("%d\n", result);
    
    return 0;
}
~~~

2. Bottom-up 방식으로 풀이

~~~ cpp
#include <cstdio>

#define MAX 1001
#define DIVIDE 10007

int arr[MAX] = { 0 };

int twoTimesN(int n) {

    for ( int i = 1; i <= n; i++ ) {

        if ( i == 1 ) {
            arr[i] = 1;
        } else if ( i == 2 ) {
            arr[i] = 2;
        } else {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        if ( arr[i] > DIVIDE ) {
            arr[i] %= DIVIDE;
        }
    }

    return arr[n];
}

int main() {
    int n;
    scanf("%d", &n);

    int result = twoTimesN(n);
    printf("%d\n", result);

    return 0;
}
~~~