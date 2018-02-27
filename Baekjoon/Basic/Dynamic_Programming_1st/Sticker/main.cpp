#include <cstdio>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_NUM 100001

int main()
{
    int cnt = 0;
    scanf("%d", &cnt);
    
    while ( cnt-- ) {
        int a[MAX_NUM][2] = { 0 };
        int d[MAX_NUM][3] = { 0 };

        int n = 0;
        scanf("%d", &n);
        
        for ( int i = 1; i <= n; ++i ) {
            scanf("%d", &a[i][0]);
        }

        for ( int i = 1; i <= n; ++i ) {
            scanf("%d", &a[i][1]);
        }
        
        for ( int i = 1; i <= n; ++i ) {
            d[i][0] = MAX(d[i - 1][0], MAX(d[i - 1][1], d[i - 1][2]));
            d[i][1] = MAX(d[i - 1][0], d[i - 1][2]) + a[i][0];
            d[i][2] = MAX(d[i - 1][0], d[i - 1][1]) + a[i][1];
        }
        
        int result = MAX(d[n][0], MAX(d[n][1], d[n][2]));
        printf("%d\n", result);
    }
    
    return 0;
}