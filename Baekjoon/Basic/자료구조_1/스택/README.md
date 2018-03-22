10828번 스택
----------

스택은 LIFO 방식으로 데이터를 처리하는 자료구조입니다.  
대표적인 연산은 push, pop, top, empty, size 가 있습니다.  
스택은 array를 이용해 구현할 수 있으며, STL에 구현되어 있는 stack을 사용하는 쪽을 더욱 추천합니다.  

1. STL 사용

~~~ cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    stack<int> s;

    while ( cnt-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push" ) {
            int n = 0;
            cin >> n;
            s.push(n);
        } else if ( cmd == "pop" ) {
            cout << (s.empty() ? -1 : s.top()) << endl;
            if ( !s.empty() ) {
                s.pop();
            }
        } else if ( cmd == "size" ) {
            cout << s.size() << endl;
        } else if ( cmd == "empty" ) {
            cout << (s.empty() ? 1 : 0) << endl;
        } else if ( cmd == "top" ) {
            cout << (s.empty() ? -1 : s.top()) << endl;
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

struct Stack {
    int data[MAX];
    int size;

    Stack() {
        data[MAX] = { 0 };
        size = 0;
    }

    void push(int num) {
        data[size] = num;
        size += 1;
    }

    int pop() {
        if ( empty() ) {
            return -1;
        } else {
            size -= 1;
            return data[size];
        }
    }

    bool empty() {
        return ((size == 0) ? true : false);
    }

    int top() {
        if ( empty() ) {
            return -1;
        } else {
            return data[size - 1];
        }   
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    Stack s;

    while ( cnt-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push" ) {
            int n = 0;
            cin >> n;
            s.push(n);
        } else if ( cmd == "pop" ) {
            cout << (s.empty() ? -1 : s.top()) << endl;
            if ( !s.empty() ) {
                s.pop();
            }
        } else if ( cmd == "size" ) {
            cout << s.size << endl;
        } else if ( cmd == "empty" ) {
            cout << (s.empty() ? 1 : 0) << endl;
        } else if ( cmd == "top" ) {
            cout << (s.empty() ? -1 : s.top()) << endl;
        }
    }

    return 0;
}
~~~