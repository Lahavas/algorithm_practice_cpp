10845번 큐
---------

1. STL 사용

~~~ cpp
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    queue<int> queue;

    while ( test_case-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push" ) {
            int num;
            cin >> num;
            queue.push(num);
        } else if ( cmd == "pop" ) {
            cout << (queue.empty() ? -1 : queue.front()) << endl;
            if ( !queue.empty() ) {
                queue.pop();
            }
        } else if ( cmd == "size" ) {
            cout << queue.size() << endl;
        } else if ( cmd == "empty" ) {
            cout << (queue.empty() ? 1 : 0) << endl;
        } else if ( cmd == "front" ) {
            cout << (queue.empty() ? -1 : queue.front()) << endl;
        } else if ( cmd == "back" ) {
            cout << (queue.empty() ? -1 : queue.back()) << endl;
        }
    }

    return 0;
}
~~~