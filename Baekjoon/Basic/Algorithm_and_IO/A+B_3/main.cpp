#include <cstdio>

int main()  {
    int test_case;
    scanf("%d", &test_case);

    while ( test_case-- ) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}