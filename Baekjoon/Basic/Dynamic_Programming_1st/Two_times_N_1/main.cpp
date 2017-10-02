#include <cstdio>

#define MAX 1001
#define DIVIDE 10007

int arr[MAX] = { 0 };

int twoTimesN(int n) {
    if ( n == 1 ) {
        arr[n] = 1;
    } else if ( n == 2 ) {
        arr[n] = 2;
    } else {
        arr[n] = twoTimesN(n - 1) + twoTimesN(n - 2);
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