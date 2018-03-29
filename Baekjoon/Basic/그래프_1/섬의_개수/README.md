4963번 섬의 개수
-------------

연결되어있는 정점끼리 이동이 가능한 섬이며, 전체 섬의 개수를 구하는 문제입니다.  
배열 check는 섬으로써 탐색된 정점을 표시하기 위한 배열입니다.  
연결 조건을 dx, dy라는 배열에 저장하고, DFS와 BFS를 통해 그래프를 탐색하며 인접하지 않은 섬이 발견될 때마다 섬의 개수를 늘려가며 문제를 해결할 수 있습니다.  

1. DFS를 사용하여 그래프를 탐색

~~~ cpp
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
~~~

2. BFS를 사용하여 그래프를 탐색

~~~ cpp
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX = 50;
constexpr int DIR_SIZE = 8;

int a[MAX][MAX] = { 0 };
bool check[MAX][MAX] = { false };

int dx[DIR_SIZE] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[DIR_SIZE] = { 1, -1, 0, 0, 1, -1, 1, -1 };

void bfs(int n, int m, int x, int y)
{
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    check[x][y] = true;

    while ( !q.empty() ) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for ( int t = 0; t < DIR_SIZE; ++t ) {
            int nx = x + dx[t];
            int ny = y + dy[t];

            if ( nx >= 0 && nx < n && ny >= 0 && ny < m ) {
                if ( a[nx][ny] == 1 && check[nx][ny] == false ) {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                }
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
                    bfs(n, m, i, j);
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
~~~