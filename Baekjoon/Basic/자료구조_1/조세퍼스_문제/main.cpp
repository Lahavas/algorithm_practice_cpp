#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int m = 0, n = 0;
    cin >> m >> n;

    queue<int> q;

    for ( int i = 1; i <= m; ++i ) {
        q.push(i);
    }

    cout << '<';

    while ( !q.empty() ) {
        for ( int i = 1; i <= n; ++i ) {
            if ( i == n ) {
                cout << q.front();
                q.pop();
            } else {
                q.push(q.front());
                q.pop();
            }
        }

        if ( q.size() != 0 ) {
            cout << ", ";
        }
    }

    cout << '>' << '\n';

    return 0;
}