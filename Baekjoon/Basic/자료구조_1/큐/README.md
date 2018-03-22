10845번 큐
---------

큐는 FIFO 방식으로 데이터를 처리하는 자료구조입니다.  
대표적인 연산은 push, pop, front, empty, size 가 있습니다.  
큐는 array를 이용해 구현할 수 있으며, STL에 구현되어 있는 queue를 사용하는 쪽을 더욱 추천합니다.  

1. STL 사용

~~~ cpp
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
~~~

2. 직접 구현

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

constexpr int MAX = 10000;

struct Queue {
    int data[MAX];
    int begin, end;

    Queue() {
        data[MAX] = { 0 };
        begin = 0;
        end = 0;
    }

    void push(int num) {
        data[end] = num;
        end += 1;
    }

    int pop() {
        if ( empty() ) {
            return -1;
        }

        begin += 1;
        return data[begin - 1];
    }

    bool empty() {
        return ((begin == end) ? true : false);
    }

    int size() {
        return end - begin;
    }

    int front() {
        return data[begin];
    }

    int back() {
        return data[end - 1];
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    Queue q;

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
~~~