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
            if ( !check[next] ) {
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