#include <cstdio>

int main() 
{
    int cnt = 0;
    scanf("%d", &cnt);

    int sum = 0;

    while ( cnt-- ) {
        int num = 0;
        scanf("%1d", &num);
        sum += num;
    }

    printf("%d\n", sum);

    return 0;
}