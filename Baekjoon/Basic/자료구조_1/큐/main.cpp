#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    queue<int> q;

    while ( cnt-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push" ) {
            int num = 0;
            cin >> num;
            q.push(num);
        } else if ( cmd == "pop" ) {
            cout << (q.empty() ? -1 : q.front()) << '\n';
            if ( !q.empty() ) {
                q.pop();
            }
        } else if ( cmd == "size" ) {
            cout << q.size() << '\n';
        } else if ( cmd == "empty" ) {
            cout << (q.empty() ? 1 : 0) << '\n';
        } else if ( cmd == "front" ) {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        } else if ( cmd == "back" ) {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        }
    }

    return 0;
}