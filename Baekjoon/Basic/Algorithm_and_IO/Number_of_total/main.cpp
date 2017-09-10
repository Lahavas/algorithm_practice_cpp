#include <cstdio>

int main(void)
{
    int cnt;
    scanf("%d", &cnt);

    int sum = 0;

    while (cnt--) {
        int input;
        scanf("%1d", &input);

        sum += input;
    }

    printf("%d\n", sum);

    return 0;
}