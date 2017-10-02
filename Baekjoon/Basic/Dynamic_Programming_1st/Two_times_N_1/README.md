11726번 2xn 타일링
----------------

2. Bottom-up 방식으로 풀이

~~~ cpp
#include <cstdio>

#define MAX 1001
#define DIVIDE 10007

int arr[MAX] = { 0 };

void twoTimesN(int n) {

    for ( int i = 1; i <= n; i++ ) {

        if ( i == 1 ) {
            arr[i] = 1;
        } else if ( i == 2) {
            arr[i] = 2;
        } else {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        if ( arr[i] > DIVIDE ) {
            arr[i] %= DIVIDE;
        }
    }

    return;
}

int main() {
    int n;
    scanf("%d", &n);

    twoTimesN(n);

    int result = arr[n];
    printf("%d\n", result);

    return 0;
}
~~~