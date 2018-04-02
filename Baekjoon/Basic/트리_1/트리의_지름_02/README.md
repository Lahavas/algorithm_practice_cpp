1967번 트리의 지름
---------------

트리의 지름을 구하기 위해서는 두 번의 탐색이 필요합니다.  

1. 루트에서 모든 정점까지의 거리를 계산. 이 때, 가장 먼 거리의 정점을 A로 지정
2. A를 루트라고 하고 모든 정점까지의 거리를 계산. 이 때, 가장 먼 거리가 지름

DFS 또는 BFS를 사용하여 트리의 탐색을 수행하여 문제를 해결할 수 있습니다.  

1. DFS를 사용하여 트리를 탐색

~~~ cpp
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Edge {
    int to;
    int cost;

    Edge(int to, int cost) : to(to), cost(cost) {

    }
};

constexpr int MAX = 10001;

vector<Edge> a[MAX];

bool check[MAX] = { false };
int dist[MAX] = { 0 };

void dfs(int node)
{
    check[node] = true;

    for ( int i = 0; i < a[node].size(); ++i ) {
        Edge &e = a[node][i];

        if ( check[e.to] == false ) {
            dist[e.to] = dist[node] + e.cost;
            dfs(e.to);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 0; i < n - 1; ++i ) {
        int u = 0, v = 0, w = 0;
        cin >> u >> v >> w;

        a[u].push_back(Edge(v, w));
        a[v].push_back(Edge(u, w));
    }

    memset(check, false, sizeof(check));
    memset(dist, 0, sizeof(dist));
    dfs(1);
    int start = 1;
    for ( int i = 2; i <= n; ++i ) {
        if (dist[i] > dist[start]) {
            start = i;
        }
    }

    memset(check, false, sizeof(check));
    memset(dist, 0, sizeof(dist));
    dfs(start);
    int res = dist[1];
    for ( int i = 2; i <= n; ++i ) {
        if (res < dist[i]) {
            res = dist[i];
        }
    }

    cout << res << '\n';

    return 0;
}
~~~

2. BFS를 사용하여 트리를 탐색

~~~ cpp
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Edge {
    int to;
    int cost;

    Edge(int to, int cost) : to(to), cost(cost) {

    }
};

constexpr int MAX = 10001;

vector<Edge> a[MAX];

bool check[MAX] = { false };
int dist[MAX] = { 0 };

void bfs(int start)
{
    memset(check, false, sizeof(check));
    memset(dist, 0, sizeof(dist));

    queue<int> q;

    check[start] = true;
    q.push(start);

    while ( !q.empty() ) {
        int node = q.front();
        q.pop();

        for ( int i = 0; i < a[node].size(); ++i ) {
            Edge &e = a[node][i];

            if ( check[e.to] == false ) {
                dist[e.to] = dist[node] + e.cost;
                q.push(e.to);
                check[e.to] = true;
            }
        } 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 0; i < n - 1; ++i ) {
        int u = 0, v = 0, w = 0;
        cin >> u >> v >> w;

        a[u].push_back(Edge(v, w));
        a[v].push_back(Edge(u, w));
    }

    bfs(1);
    int start = 1;
    for ( int i = 2; i <= n; ++i ) {
        if (dist[i] > dist[start]) {
            start = i;
        }
    }

    bfs(start);
    int res = dist[1];
    for ( int i = 2; i <= n; ++i ) {
        if (res < dist[i]) {
            res = dist[i];
        }
    }

    cout << res << '\n';

    return 0;
}
~~~