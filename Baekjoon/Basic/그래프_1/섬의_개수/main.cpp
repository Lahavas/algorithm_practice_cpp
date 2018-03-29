#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX = 50;
constexpr int DIR_SIZE = 8;

int a[MAX][MAX] = { 0 };
bool check[MAX][MAX] = { false };

int dx[DIR_SIZE] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[DIR_SIZE] = { 1, -1, 0, 0, 1, -1, 1, -1 };

void dfs(int n, int m, int x, int y)
{
    check[x][y] = true;

    for ( int t = 0; t < DIR_SIZE; ++t ) {
        int nx = x + dx[t];
        int ny = y + dy[t];

        if ( nx >= 0 && nx < n && ny >= 0 && ny < m ) {
            if ( a[nx][ny] == 1 && check[nx][ny] == false ) {
                dfs(n, m, nx, ny);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0, m = 0;

    while ( true ) {
        memset(a, 0, sizeof(a));
        memset(check, false, sizeof(check));

        cin >> m >> n;
        if ( n == 0 && m == 0 ) {
            break;
        }

        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                cin >> a[i][j];
            }
        }

        int cnt = 0;
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                if ( a[i][j] == 1 && check[i][j] == false ) {
                    cnt += 1;
                    dfs(n, m, i, j);
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}