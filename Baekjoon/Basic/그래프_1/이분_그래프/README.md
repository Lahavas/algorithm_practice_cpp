1707번 이분 그래프
---------------

그래프를 A와 B로 나눌 수 있으면 이분 그래프 (Bipartite Graph) 라고 합니다.  
DFS와 BFS를 사용하여 모든 정점을 탐색하고 각 정점을 A와 B로 나누어 이분 그래프인지 아닌지를 확인할 수 있습니다.  
방문하지 않은 정점을 0으로, 그래프의 A에 해당하는 정점을 1로, 그래프의 B에 해당하는 정점을 2로 두어 문제를 해결할 수 있습니다.  

1. DFS를 사용하여 그래프를 탐색

~~~ cpp
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr int NODE_SIZE = 20001;

vector<int> a[NODE_SIZE];
int color[NODE_SIZE] = { 0 };

void dfs(int node, int c)
{
    color[node] = c;

    for ( int i = 0; i < a[node].size(); ++i ) {
        int next = a[node][i];
        if ( color[next] == 0 ) {
            dfs(next, 3 - c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    while ( cnt-- ) {
        for ( auto &e : a ) {
            e.clear();
        }
        memset(color, 0, sizeof(color));

        int n = 0, m = 0;
        cin >> n >> m;

        for ( int i = 0; i < m; ++i ) {
            int u = 0, v = 0;
            cin >> u >> v;

            a[u].push_back(v);
            a[v].push_back(u);
        }

        for ( int i = 1; i <= n; ++i ) {
            if ( color[i] == 0 ) {
                dfs(i, 1);
            }
        }

        bool check = true;
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = 0; j < a[i].size(); ++j ) {
                int t = a[i][j];
                if ( color[i] == color[t] ) {
                    check = false;
                }
            }
        }

        cout << (check == true ? "YES" : "NO") << '\n';
    }

    return 0;
}
~~~