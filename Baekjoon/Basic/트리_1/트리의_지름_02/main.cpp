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