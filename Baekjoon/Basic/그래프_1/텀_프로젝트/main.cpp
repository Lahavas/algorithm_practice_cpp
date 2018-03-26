#include <cstdio>

constexpr int MAX = 100001;

int a[MAX] = { 0 };
int d[MAX] = { 0 };
int s[MAX] = { 0 };

int n = 0;

int dfs(int x, int cnt, int &step) 
{
    if ( d[x] != 0 ) {
        if ( step != s[x] ) {
            return 0;
        }
        return cnt - d[x];
    }
    d[x] = cnt;
    s[x] = step;
    return dfs(a[x], cnt + 1, step);
}

int main() 
{
    int cnt = 0;
    scanf("%d", &cnt);

    while ( cnt-- ) {
        scanf("%d", &n);

        for ( int i = 1; i <= n; ++i ) {
            scanf("%d", &a[i]);
            d[i] = 0;
            s[i] = 0;
        }

        int res = 0;

        for ( int i = 1; i <= n; ++i ) {
            if (d[i] == 0) {
                res += dfs(i, 1, i);
            }
        }

        printf("%d\n", n - res);
    }
    return 0;
}