#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 1000;
constexpr int DIR_NUM = 4;

int a[MAX][MAX] = { 0 };
int d[MAX][MAX] = { 0 };

int dx[DIR_NUM] = { 0, 0, 1, -1 };
int dy[DIR_NUM] = { 1, -1, 0, 0 };

void bfs(int n, int m)
{
    queue<pair<int, int>> q;
    
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m; ++j ) {
            if ( a[i][j] == 1 ) {
                q.push(make_pair(i, j));
            }
        }
    }

    while ( !q.empty() ) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for ( int t = 0; t < DIR_NUM; ++t ) {
            int nx = x + dx[t];
            int ny = y + dy[t];

            if ( nx >= 0 && nx < n && ny >= 0 && ny < m ) {
                if ( a[nx][ny] == 0 && d[nx][ny] == -1 ) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> m >> n;

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m; ++j ) {
            cin >> a[i][j];
            d[i][j] = (a[i][j] == 1 ? 0 : -1);
        }
    }

    bfs(n, m);

    int res = 0;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m; ++j ) {
            if ( res < d[i][j] ) {
                res = d[i][j];
            }
        }
    }

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m; ++j ) {
            if ( a[i][j] == 0 && d[i][j] == -1 ) {
                res = -1;
            }
        }
    }

    cout << res << '\n';

    return 0;
}