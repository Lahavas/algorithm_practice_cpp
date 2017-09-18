#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    queue<int> q;

    while ( tc-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push" ) {
            int num;
            cin >> num;
            q.push(num);
        } else if ( cmd == "pop" ) {
            cout << (q.empty() ? -1 : q.front()) << endl;
            if ( !q.empty() ) {
                q.pop();
            }
        } else if ( cmd == "size" ) {
            cout << q.size() << endl;
        } else if ( cmd == "empty" ) {
            cout << (q.empty() ? 1 : 0) << endl;
        } else if ( cmd == "front" ) {
            cout << (q.empty() ? -1 : q.front()) << endl;
        } else if ( cmd == "back" ) {
            cout << (q.empty() ? -1 : q.back()) << endl;
        }
    }

    return 0;
}