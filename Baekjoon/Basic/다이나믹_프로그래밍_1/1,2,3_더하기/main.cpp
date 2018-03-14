#include <cstdio>

constexpr int MAX = 11;

int d[MAX] = { 0 };

int main()
{
    int cnt = 0;
    scanf("%d", &cnt);

    while ( cnt-- ) {
        int n = 0;
        scanf("%d", &n);

        for ( int i = 1; i <= n; ++i ) {
            if ( i == 1 ) {
                d[i] = 1;
            } else if ( i == 2 ) {
                d[i] = 2;
            } else if ( i == 3 ) {
                d[i] = 4;
            } else {
                d[i] = d[i - 1] + d[i - 2] + d[i - 3];
            }
        }
        
        int result = d[n];
        printf("%d\n", result);
    }

    return 0;
}