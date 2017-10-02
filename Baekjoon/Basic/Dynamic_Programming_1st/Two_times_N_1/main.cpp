#include <cstdio>

#define MAX 1001
#define DIVIDE 10007

int arr[MAX] = { 0 };

int twoTimesN(int n) {

    arr[1] = 1;
    arr[2] = 2;

    for ( int i = 3; i <= n; i++ ) {
        arr[i] = arr[i - 1] + arr[i - 2];

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