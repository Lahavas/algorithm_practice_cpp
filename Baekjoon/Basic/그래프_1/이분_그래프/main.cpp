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