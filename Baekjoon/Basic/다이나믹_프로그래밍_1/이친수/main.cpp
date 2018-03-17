#include <cstdio>

constexpr int MAX = 91;

long d[MAX][2] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        if ( i == 1 ) {
            d[i][1] = 1;
            continue;
        } else if ( i == 2 ) {
            d[i][0] = 1;
            continue;
        }

        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }

    printf("%ld\n", d[n][0] + d[n][1]);

    return 0;
}