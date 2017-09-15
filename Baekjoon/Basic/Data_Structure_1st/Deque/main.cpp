#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    deque<int> deque;

    while ( test_case-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push_front" ) {
            int num;
            cin >> num;
            deque.push_front(num);
        } else if ( cmd == "push_back" ) {
            int num;
            cin >> num;
            deque.push_back(num);
        } else if ( cmd == "pop_front" ) {
            cout << (deque.empty() ? -1 : deque.front()) << endl;
            if ( !deque.empty() ) {
                deque.pop_front();
            }
        } else if ( cmd == "pop_back" ) {
            cout << (deque.empty() ? -1 : deque.back()) << endl;
            if ( !deque.empty() ) {
                deque.pop_back();
            }
        } else if ( cmd == "size" ) {
            cout << deque.size() << endl;
        } else if ( cmd == "empty" ) {
            cout << (deque.empty() ? 1 : 0) << endl;
        } else if ( cmd == "front" ) {
            cout << (deque.empty() ? -1 : deque.front()) << endl;
        } else if ( cmd == "back" ) {
            cout << (deque.empty() ? -1 : deque.back()) << endl;
        }
    }

    return 0;
}