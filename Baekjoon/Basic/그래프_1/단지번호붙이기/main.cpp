#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX = 30;
constexpr int DIR_NUM = 4;

int a[MAX][MAX] = { 0 };
int d[MAX][MAX] = { 0 };

int dx[DIR_NUM] = { 0, 0, 1, -1 };
int dy[DIR_NUM] = { 1, -1, 0, 0 };

void bfs(int n, int x, int y, int cnt)
{
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    d[x][y] = cnt;

    while ( !q.empty() ) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for ( int t = 0; t < DIR_NUM; ++t ) {
            int nx = x + dx[t];
            int ny = y + dy[t];

            if ( nx >= 0 && nx < n && ny >= 0 && ny < n ) {
                if ( a[nx][ny] == 1 && d[nx][ny] == 0 ) {
                    q.push(make_pair(nx, ny));
                    d[nx][ny] = cnt;
                }
            }
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            scanf("%1d", &a[i][j]);
        }
    }

    int cnt = 0;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            if ( a[i][j] == 1 && d[i][j] == 0 ) {
                cnt += 1;
                bfs(n, i, j, cnt);
            }
        }
    }

    printf("%d\n", cnt);

    vector<int> res(cnt, 0);
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            if ( d[i][j] != 0 ) {
                res[d[i][j] - 1] += 1;
            }
        }
    }

    sort(res.begin(), res.end());

    for ( auto e : res ) {
        printf("%d\n", e);
    }

    return 0;
}