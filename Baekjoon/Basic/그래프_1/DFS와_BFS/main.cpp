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