#include <cstdio>

int main() {
    int test_case;
    scanf("%d", &test_case);

    int sum = 0;

    while ( test_case-- ) {
        int num;
        scanf("%1d", &num);
        sum += num;
    }

    printf("%d\n", sum);

    return 0;
}