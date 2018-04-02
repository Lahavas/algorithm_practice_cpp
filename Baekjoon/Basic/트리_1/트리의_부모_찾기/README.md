11725번 트리의 부모 찾기
--------------------

주어진 입력값을 그래프의 간선처럼 저장하고, 정점 간의 연결과 깊이를 이용하여 부모 노드와 자식 노드를 구분할 수 있습니다.  
BFS 또는 DFS를 사용하여 각 노드의 부모 노드를 저장하고, 이를 출력하는 방식으로 문제를 해결할 수 있습니다.  

1. DFS를 사용하여 트리를 탐색

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 100001;

vector<int> a[MAX];

int parent[MAX] = { 0 };
bool check[MAX] = { false };

void dfs(int node)
{
    check[node] = true;

    for ( int next : a[node] ) {
        if ( check[next] == false ) {
            check[next] = true;
            parent[next] = node;

            dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 0; i < n - 1; ++i ) {
        int u = 0, v = 0;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1);

    for ( int i = 2; i <= n; ++i ) {
        cout << parent[i] << '\n';
    }

    return 0;
}
~~~

2. BFS를 사용하여 트리를 탐색

~~~ cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX = 100001;

vector<int> a[MAX];

int parent[MAX] = { 0 };
bool check[MAX] = { false };

void bfs(int start)
{
    queue<int> q;

    check[start] = true;
    parent[start] = 0;

    q.push(start);

    while ( !q.empty() ) {
        int node = q.front();
        q.pop();

        for ( int next : a[node] ) {
            if ( check[next] == false ) {
                check[next] = true;
                parent[next] = node;
                q.push(next);
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
        int u = 0, v = 0;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    bfs(1);

    for ( int i = 2; i <= n; ++i ) {
        cout << parent[i] << '\n';
    }

    return 0;
}
~~~