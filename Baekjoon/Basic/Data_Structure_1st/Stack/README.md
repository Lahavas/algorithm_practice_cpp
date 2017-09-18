10828번 스택
----------

1. STL 사용

~~~ cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    stack<int> st;

    while ( tc-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push" ) {
            int num;
            cin >> num;
            st.push(num);
        } else if ( cmd == "pop" ) {
            cout << (st.empty() ? -1 : st.top()) << endl;
            if ( !st.empty() ) {
                st.pop();
            }
        } else if ( cmd == "size" ) {
            cout << st.size() << endl;
        } else if ( cmd == "empty" ) {
            cout << (st.empty() ? 1 : 0) << endl;
        } else if ( cmd == "top" ) {
            cout << (st.empty() ? -1 : st.top()) << endl;
        }
    }

    return 0;
}
~~~

2. 직접 구현

~~~ cpp
#include <iostream>
#include <string>

#define MAX 10000

using namespace std;

struct Stack {
    int data[MAX];
    int size;

    Stack() {
        size = 0;
    }

    void push(int num) {
        data[size] = num;
        size++;
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

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    Stack st;

    while ( tc-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push" ) {
            int num;
            cin >> num;
            st.push(num);
        } else if ( cmd == "pop" ) {
            cout << (st.empty() ? -1 : st.top()) << endl;
            if ( !st.empty() ) {
                st.pop();
            }
        } else if ( cmd == "size" ) {
            cout << st.size << endl;
        } else if ( cmd == "empty" ) {
            cout << (st.empty() ? 1 : 0) << endl;
        } else if ( cmd == "top" ) {
            cout << (st.empty() ? -1 : st.top()) << endl;
        }
    }

    return 0;
}
~~~