#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    deque<int> dq;

    while ( tc-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push_front" ) {
            int num;
            cin >> num;
            dq.push_front(num);
        } else if ( cmd == "push_back" ) {
            int num;
            cin >> num;
            dq.push_back(num);
        } else if ( cmd == "pop_front" ) {
            cout << (dq.empty() ? -1 : dq.front()) << endl;
            if ( !dq.empty() ) {
                dq.pop_front();
            }
        } else if ( cmd == "pop_back" ) {
            cout << (dq.empty() ? -1 : dq.back()) << endl;
            if ( !dq.empty() ) {
                dq.pop_back();
            }
        } else if ( cmd == "size" ) {
            cout << dq.size() << endl;
        } else if ( cmd == "empty" ) {
            cout << (dq.empty() ? 1 : 0) << endl;
        } else if ( cmd == "front" ) {
            cout << (dq.empty() ? -1 : dq.front()) << endl;
        } else if ( cmd == "back" ) {
            cout << (dq.empty() ? -1 : dq.back()) << endl;
        }
    }

    return 0;
}