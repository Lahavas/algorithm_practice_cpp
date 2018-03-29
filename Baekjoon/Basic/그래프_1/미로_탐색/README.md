2178번 미로 탐색
--------------

미로에서 가장 빠른 길을 구하는 문제입니다.  
dist 배열은 시작 정점에서 해당 정점까지의 거리를 나타내는 배열이며, dist[next] = dist[now] + 1 임을 알 수 있습니다.  
BFS의 경우, 모든 가중치가 1일 때 최단 거리 알고리즘을 구할 수 있다는 특징을 가지고 있기 때문에,  
본 문제는 DFS가 아닌 BFS를 사용하여 문제를 해결할 수 있습니다.  

~~~ cpp
#include <cstdio>
#include <queue>

using namespace std;

constexpr int MAX = 100;
constexpr int DIR_NUM = 4;

int a[MAX][MAX] = { 0 };
int dist[MAX][MAX] = { 0 };
bool check[MAX][MAX] = { false };

int dx[DIR_NUM] = { 0, 0, 1, -1 };
int dy[DIR_NUM] = { 1, -1, 0, 0 };

void bfs(int n, int m, int x, int y)
{
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    dist[x][y] = 1;
    check[x][y] = true;

    while ( !q.empty() ) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for ( int t = 0; t < DIR_NUM; ++t ) {
            int nx = x + dx[t];
            int ny = y + dy[t];

            if ( nx >= 0 && nx < n && ny >= 0 && ny < m ) {
                if ( a[nx][ny] == 1 && check[nx][ny] == false ) {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                    check[nx][ny] = true;
                }
            }
        }
    }
}

int main()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m; ++j ) {
            scanf("%1d", &a[i][j]);
        }
    }

    bfs(n, m, 0, 0);

    printf("%d\n", dist[n - 1][m - 1]);

    return 0;
}
~~~