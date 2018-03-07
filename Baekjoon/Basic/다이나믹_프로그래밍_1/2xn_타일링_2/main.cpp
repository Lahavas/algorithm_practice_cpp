#include <cstdio>

#define MAX 1001
#define DIVIDE 10007

int arr[MAX] = { 0 };

int twoTimesN(int n) {

    for ( int i = 1; i <= n; i++ ) {

        if ( i == 1 ) {
            arr[i] = 1;
        } else if ( i == 2 ) {
            arr[i] = 3;
        } else {
            arr[i] = arr[i - 1] + arr[i - 2] * 2;
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