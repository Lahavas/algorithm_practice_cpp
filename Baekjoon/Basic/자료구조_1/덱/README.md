10866번 덱
---------

덱은 Double-ended queue의 약자입니다.  
대표적인 연산은 push_front, push_back, pop_front, pop_back, front, back 등이 있습니다.  

~~~ cpp
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    deque<int> dq;

    while ( cnt-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push_front" ) {
            int num = 0;
            cin >> num;
            dq.push_front(num);
        } else if ( cmd == "push_back" ) {
            int num;
            cin >> num;
            dq.push_back(num);
        } else if ( cmd == "pop_front" ) {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
            if ( !dq.empty() ) {
                dq.pop_front();
            }
        } else if ( cmd == "pop_back" ) {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
            if ( !dq.empty() ) {
                dq.pop_back();
            }
        } else if ( cmd == "size" ) {
            cout << dq.size() << '\n';
        } else if ( cmd == "empty" ) {
            cout << (dq.empty() ? 1 : 0) << '\n';
        } else if ( cmd == "front" ) {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
        } else if ( cmd == "back" ) {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
        }
    }

    return 0;
}
~~~