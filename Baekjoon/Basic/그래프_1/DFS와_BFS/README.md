1260번 DFS와 BFS
---------------

가중치가 없는 양방향 그래프에 대하여 DFS와 BFS를 사용하여 그래프를 탐색하는 문제입니다.  
다양한 방법을 통해 문제를 해결할 수 있지만, 여기서는 인접 행렬과 인접 리스트, 그리고 간선 리스트를 통해 문제를 풀이하였습니다.  

1. 인접 행렬 (Adjacency Matrix) 를 사용하여 그래프를 표현

~~~ cpp
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

constexpr int NODE_SIZE = 1001;

int a[NODE_SIZE][NODE_SIZE] = { 0 };
bool check[NODE_SIZE] = { false };

void dfs(int n, int node)
{
    check[node] = true;
    printf("%d ", node);

    for ( int i = 1; i <= n; ++i ) {
        if ( a[node][i] == 1 && check[i] == false ) {
            dfs(n, i);
        }
    }
}

void bfs(int n, int start)
{
    queue<int> q;

    check[start] = true;
    q.push(start);

    while ( !q.empty() ) {
        int node = q.front();
        q.pop();
        printf("%d ", node);

        for ( int i = 1; i <= n; ++i ) {
            if ( a[node][i] == 1 && check[i] == false ) {
                check[i] = true;    
                q.push(i);
            }
        }
    }
}

int main()
{       
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    
    int start = 0;
    scanf("%d", &start);
    
    for ( int i = 0; i < m; ++i ) {
        int u = 0, v = 0;
        scanf("%d %d", &u, &v);
        
        a[u][v] = a[v][u] = 1;
    }
    
    memset(check, false, sizeof(check));
    dfs(n, start);
    putchar('\n');

    memset(check, false, sizeof(check));
    bfs(n, start);
    putchar('\n');
    
    return 0;
}
~~~

2. 인접 리스트 (Adjacency List) 를 사용하여 그래프를 표현

~~~ cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int NODE_SIZE = 1001;

vector<int> a[NODE_SIZE];
bool check[NODE_SIZE] = { false };

void dfs(int node)
{
    check[node] = true;
    cout << node << ' ';

    for ( int i = 0; i < a[node].size(); ++i ) {
        int next = a[node][i];
        if ( check[next] == false ) {
            dfs(next);
        }
    }
}

void bfs(int start)
{
    queue<int> q;

    check[start] = true;
    q.push(start);

    while ( !q.empty() ) {
        int node = q.front();
        q.pop();
        cout << node << ' ';

        for ( int i = 0; i < a[node].size(); ++i ) {
            int next = a[node][i];
            if ( check[next] == false ) {
                check[next] = true;
                q.push(next);
            }
        }
    }    
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;

    int start = 0;
    cin >> start;

    for ( int i = 0; i < m; ++i ) {
        int u = 0, v = 0;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for ( auto &e : a ) {
        sort(e.begin(), e.end());
    }

    memset(check, false, sizeof(check));
    dfs(start);
    cout << '\n';
    
    memset(check, false, sizeof(check));
    bfs(start);
    cout << '\n';

    return 0;
}
~~~

3. 간선 리스트 (Edge List) 를 사용하여 그래프를 표현

~~~ cpp
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int NODE_SIZE = 1001;
constexpr int EDGE_SIZE = 20001;

struct Edge {
    int from, to;
    int weight;

    Edge() {
        from = 0;
        to = 0;
        weight = 0;
    }
};

Edge edge[EDGE_SIZE];

int cnt[NODE_SIZE] = { 0 };
bool check[NODE_SIZE] = { false };

void dfs(int node)
{
    check[node] = true;
    printf("%d ",node);

    for ( int i = cnt[node - 1]; i < cnt[node]; ++i ) {
        int next = edge[i].to;

        if (check[next] == false) {
            dfs(next);
        }
    }
}

void bfs(int start) 
{
    queue<int> q;

    q.push(start);
    check[start] = true;

    while ( !q.empty() ) {
        int node = q.front();
        q.pop();
        printf("%d ",node);

        for ( int i = cnt[node - 1]; i < cnt[node]; ++i ) {
            int next = edge[i].to;

            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main() 
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int start = 0;
    scanf("%d", &start);

    for ( int i = 0; i < m; ++i ) {
        scanf("%d %d", &edge[i].from, &edge[i].to);

        edge[i + m].from = edge[i].to;
        edge[i + m].to = edge[i].from;
    }

    m *= 2;

    sort(edge, edge + m, [](const Edge &u, const Edge &v) {
        return (u.from == v.from ? u.to < v.to : u.from < v.from);
    });

    for ( int i = 0; i < m; ++i ) {
        cnt[edge[i].from] += 1;
    }

    for ( int i = 1; i <= n; ++i ) {
        cnt[i] += cnt[i - 1];
    }
    
    memset(check,false,sizeof(check));
    dfs(start);
    putchar('\n');

    memset(check,false,sizeof(check));
    bfs(start);
    putchar('\n');
    
    return 0;
}
~~~

4. DFS를 재귀 함수를 사용하지 않고 구현

~~~ cpp
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int NODE_SIZE = 1001;

vector<int> a[NODE_SIZE];
bool check[NODE_SIZE] = { false };

void dfs(int node)
{
    stack<pair<int, int>> s;

    s.push(make_pair(node, 0));
    check[node] = true;
    cout << node << ' ';

    while ( !s.empty() ) {
        int node = s.top().first;
        int start = s.top().second;
        s.pop();

        for ( int i = start; i < a[node].size(); ++i ) {
            int next = a[node][i];
            if ( check[next] == false ) {
                cout << next << ' ';
                check[next] = true;
                s.push(make_pair(node, i + 1));
                s.push(make_pair(next, 0));
                break;
            }
        }
    }

}

void bfs(int start)
{
    queue<int> q;

    check[start] = true;
    q.push(start);

    while ( !q.empty() ) {
        int node = q.front();
        q.pop();
        cout << node << ' ';

        for ( int i = 0; i < a[node].size(); ++i ) {
            int next = a[node][i];
            if ( check[next] == false ) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;

    int start = 0;
    cin >> start;

    for ( int i = 0; i < m; ++i ) {
        int u = 0, v = 0;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for ( auto &e : a ) {
        sort(e.begin(), e.end());
    }

    memset(check, false, sizeof(check));
    dfs(start);
    cout << '\n';

    memset(check, false, sizeof(check));
    bfs(start);
    cout << '\n';

    return 0;
}
~~~