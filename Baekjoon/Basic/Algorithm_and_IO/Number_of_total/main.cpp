#include <cstdio>

int main() {
    int cnt;
    scanf("%d", &cnt);

    int sum = 0;

    while ( cnt-- ) {
        int num;
        scanf("%1d", &num);
        sum += num;
    }

    printf("%d\n", sum);

    return 0;
}