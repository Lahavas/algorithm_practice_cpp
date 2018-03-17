#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX = 10001;

int a[MAX] = { 0 };
int d[MAX][3] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        scanf("%d", &a[i]);
    }

    d[1][1] = a[1];
    d[2][0] = a[1];
    d[2][1] = a[2];
    d[2][2] = a[1] + a[2];

    for ( int i = 3; i <= n; ++i ) {
        d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
        d[i][1] = d[i - 1][0] + a[i];
        d[i][2] = d[i - 1][1] + a[i];
    }

    int res = max(d[n][0], max(d[n][1], d[n][2]));
    printf("%d\n", res);

    return 0;
}