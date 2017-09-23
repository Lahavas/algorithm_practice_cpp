1463번 1로 만들기
--------------

1. Bottom-up 방식으로 풀이  

~~~ cpp
#include <cstdio>

#define MAX 1000001

int arr[MAX];

int makeOne(int n) {
    for ( int i = 1; i <= n; i++ ) {
        if ( i == 1 ) {
            arr[i] = 0;
            continue;
        }

        arr[i] = arr[i - 1] + 1;

        if ( i % 2 == 0 && arr[i] > arr[i / 2] + 1 ) {
            arr[i] = arr[i / 2] + 1;
        }

        if ( i % 3 == 0 && arr[i] > arr[i / 3] + 1 ) {
            arr[i] = arr[i / 3] + 1;
        }
    }

    return arr[n];
}

int main() {
    int n;
    scanf("%d", &n);

    int result = makeOne(n);

    printf("%d\n", result);

    return 0;
}
~~~