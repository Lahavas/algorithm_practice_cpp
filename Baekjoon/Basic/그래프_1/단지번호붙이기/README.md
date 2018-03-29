2667번 단지번호붙이기
----------------

연결되어있는 정점끼리 같은 단지 번호를 공유하며, 주어진 단지 내에서 단지 번호에 대한 정보를 출력하는 문제입니다.  
배열 d는 해당 정점에 부여된 단지 번호를 저장하는 배열로, 집이 없는 곳은 0을 붙입니다.  
연결 조건을 dx, dy라는 배열에 저장하고, DFS와 BFS를 통해 그래프를 탐색하며 단지 번호를 각 정점에 부여하는 방식으로 문제를 해결할 수 있습니다.  

1. DFS를 사용하여 그래프를 탐색

~~~ cpp
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 25;
constexpr int DIR_NUM = 4;

int a[MAX][MAX] = { 0 };
int d[MAX][MAX] = { 0 };

int dx[DIR_NUM] = { 0, 0, 1, -1 };
int dy[DIR_NUM] = { 1, -1, 0, 0 };

void dfs(int n, int x, int y, int cnt)
{
    d[x][y] = cnt;

    for ( int t = 0; t < DIR_NUM; ++t ) {
        int nx = x + dx[t];
        int ny = y + dy[t];

        if ( nx >= 0 && nx < n && ny >= 0 && ny < n ) {
            if ( a[nx][ny] == 1 && d[nx][ny] == 0 ) {
                dfs(n, nx, ny, cnt);
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
                dfs(n, i, j, cnt);
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
~~~

2. BFS를 사용하여 그래프를 탐색

~~~ cpp
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX = 25;
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
~~~