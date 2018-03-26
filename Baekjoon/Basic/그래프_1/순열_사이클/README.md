10451번 순열 사이클
----------------

순열이 주어졌을 때, 순열 사이클의 개수를 찾는 문제입니다.  
DFS를 사용하여 이미 방문했던 수를 다시 방문했을 때 갯수를 체크하는 방식으로 문제를 해결할 수 있습니다.  

~~~ cpp
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
~~~