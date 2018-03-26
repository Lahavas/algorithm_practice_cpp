#include <iostream>
#include <cstring>

using namespace std;

constexpr int NODE_SIZE = 1001;

int a[NODE_SIZE] = { 0 };
bool check[NODE_SIZE] = { false };

void dfs(int node)
{
    if ( check[node] == true )  {
        return;
    }

    check[node] = true;
    dfs(a[node]);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    while ( cnt-- ) {
        memset(a, 0, sizeof(a));
        memset(check, false, sizeof(check));

        int n = 0;
        cin >> n;

        for ( int i = 1; i <= n; ++i ) {
            cin >> a[i];
        }

        int res = 0;
        for ( int i = 1; i <= n; ++i ) {
            if ( check[i] == false ) {
                dfs(i);
                res += 1;
            }
        }

        cout << res << '\n';
    }

    return 0;
}