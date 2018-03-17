#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX = 100001;

int main()
{
    int cnt = 0;
    scanf("%d", &cnt);
    
    while ( cnt-- ) {
        int a[MAX][3] = { 0 };
        int d[MAX][3] = { 0 };

        int n = 0;
        scanf("%d", &n);
        
        for ( int i = 1; i <= n; ++i ) {
            scanf("%d", &a[i][1]);
        }

        for ( int i = 1; i <= n; ++i ) {
            scanf("%d", &a[i][2]);
        }
        
        for ( int i = 1; i <= n; ++i ) {
            d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
            d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][1];
            d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][2];
        }
        
        int res = max(d[n][0], max(d[n][1], d[n][2]));
        printf("%d\n", res);
    }
    
    return 0;
}