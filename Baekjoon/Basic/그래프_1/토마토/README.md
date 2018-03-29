7576번 토마토
-----------

모든 토마토가 익는 최소 일수를 구하는 문제입니다.  
d 배열은 해당 정점에 있는 토마토가 익는 일수를 나타내는 배열이며, d[next] = d[now] + 1 임을 알 수 있습니다.  
BFS의 경우, 모든 가중치가 1일 때 최단 거리 알고리즘을 구할 수 있다는 특징을 가지고 있기 때문에,  
본 문제는 DFS가 아닌 BFS를 사용하여 문제를 해결할 수 있습니다.  

~~~ cpp
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
~~~