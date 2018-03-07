9095번 1, 2, 3 더하기
-------------------

1. Top-down 방식으로 풀이

~~~cpp
#include <cstdio>

#define MAX 11

int arr[MAX] = { 0 };

int addNum(int n)
{
    if ( n == 1 ) {
        return 1;
    } else if ( n == 2 ) {
        return 2;
    } else if ( n == 3 ) {
        return 4;
    } else {
        if ( arr[n] > 0 ) {
            return arr[n];
        }

        arr[n] = addNum(n - 1) + addNum(n - 2) + addNum(n - 3);

        return arr[n];
    }
}

int main()
{
    int ts = 0;
    scanf("%d", &ts);

    while ( ts-- ) {
        int n = 0;
        scanf("%d", &n);
        
        int result = addNum(n);
        printf("%d\n", result);
    }

    return 0;
}
~~~

2. Bottom-up 방식으로 풀이  

~~~ cpp
#include <cstdio>

#define MAX 11

int arr[MAX] = { 0 };

int addNum(int n)
{
    for ( int i = 1; i <= n; i++) {
        if ( i == 1 ) {
            arr[i] = 1;
        } else if ( i == 2 ) {
            arr[i] = 2;
        } else if ( i == 3 ) {
            arr[i] = 4;
        } else {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }
    }

    return arr[n];
}

int main()
{
    int ts = 0;
    scanf("%d", &ts);

    while ( ts-- ) {
        int n = 0;
        scanf("%d", &n);
        
        int result = addNum(n);
        printf("%d\n", result);
    }

    return 0;
}
~~~