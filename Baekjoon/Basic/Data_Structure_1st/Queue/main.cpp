#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    queue<int> qu;

    while ( tc-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push" ) {
            int num;
            cin >> num;
            qu.push(num);
        } else if ( cmd == "pop" ) {
            cout << (qu.empty() ? -1 : qu.front()) << endl;
            if ( !qu.empty() ) {
                qu.pop();
            }
        } else if ( cmd == "size" ) {
            cout << qu.size() << endl;
        } else if ( cmd == "empty" ) {
            cout << (qu.empty() ? 1 : 0) << endl;
        } else if ( cmd == "front" ) {
            cout << (qu.empty() ? -1 : qu.front()) << endl;
        } else if ( cmd == "back" ) {
            cout << (qu.empty() ? -1 : qu.back()) << endl;
        }
    }

    return 0;
}