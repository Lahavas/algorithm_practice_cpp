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