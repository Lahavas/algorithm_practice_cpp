#include <cstdio>

int main() {
    int tc;
    scanf("%d", &tc);

    int sum = 0;

    while ( tc-- ) {
        int num;
        scanf("%1d", &num);
        sum += num;
    }

    printf("%d\n", sum);

    return 0;
}