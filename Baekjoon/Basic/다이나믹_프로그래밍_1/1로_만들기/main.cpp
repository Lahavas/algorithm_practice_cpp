#include <cstdio>

constexpr int MAX = 1000001;

int d[MAX] = { 0 };

int main() 
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        if ( i == 1 ) {
            d[i] = 0;
            continue;
        }

        d[i] = d[i - 1] + 1;

        if ( i % 2 == 0 && d[i] > d[i / 2] + 1 ) {
            d[i] = d[i / 2] + 1;
        }

        if ( i % 3 == 0 && d[i] > d[i / 3] + 1 ) {
            d[i] = d[i / 3] + 1;
        }
    }

    int result = d[n];

    printf("%d\n", result);

    return 0;
}