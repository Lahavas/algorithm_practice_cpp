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