#include <cstdio>

constexpr int MAX = 1001;
constexpr int mod = 10007;

int d[MAX] = { 0 };

int main() 
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        if ( i == 1 ) {
            d[i] = 1;
        } else if ( i == 2 ) {
            d[i] = 2;
        } else {
            d[i] = d[i - 1] + d[i - 2];
        }

        d[i] %= mod;
    }

    int result = d[n];
    printf("%d\n", result);

    return 0;
}