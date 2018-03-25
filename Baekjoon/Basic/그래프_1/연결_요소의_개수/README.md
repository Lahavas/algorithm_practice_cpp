11724번 연결 요소의 개수
--------------------

그래프의 연결 요소 (Connected Component) 의 개수를 구하는 문제입니다.  
전체 정점을 탐색하며 연결 요소를 확인하는 문제이기 때문에 인접 리스트에 대하여 정렬을 실행할 필요는 없습니다.  
DFS와 BFS를 사용하여 문제를 해결할 수 있습니다.  

1. DFS를 사용하여 연결 요소의 갯수 구하기

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

constexpr int NODE_SIZE = 1001;

vector<int> a[NODE_SIZE];
bool check[NODE_SIZE] = { false };

void dfs(int node)
{
    check[node] = true;
    
    for ( int i = 0; i < a[node].size(); ++i ) {
        int next = a[node][i];
        if ( check[next] == false ) {
            dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n = 0, m = 0;
    cin >> n >> m;
    
    for ( int i = 0; i < m; ++i ) {
        int u = 0, v = 0;
        cin >> u >> v;
        
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    int components = 0;
    for ( int i = 1; i <= n; ++i ) {
        if ( check[i] == false ) {
            dfs(i);
            components += 1;
        }
    }
    
    cout << components << '\n';
    
    return 0;
}
~~~

2. BFS를 사용하여 연결 요소의 갯수 구하기

~~~ cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int NODE_SIZE = 1001;

vector<int> a[NODE_SIZE];
bool check[NODE_SIZE] = { false };

void bfs(int start)
{
    queue<int> q;

    check[start] = true;
    q.push(start);

    while ( !q.empty() ) {
        int node = q.front();
        q.pop();

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
    
    for ( int i = 0; i < m; ++i ) {
        int u = 0, v = 0;
        cin >> u >> v;
        
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    int components = 0;
    for ( int i = 1; i <= n; ++i ) {
        if ( check[i] == false ) {
            bfs(i);
            components += 1;
        }
    }
    
    cout << components << '\n';
    
    return 0;
}
~~~