#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    stack<int> stack;

    while ( test_case-- ) {
        string cmd;
        cin >> cmd;

        if ( cmd == "push" ) {
            int num;
            cin >> num;
            stack.push(num);
        } else if ( cmd == "pop" ) {
            cout << (stack.empty() ? -1 : stack.top()) << endl;
            if ( !stack.empty() ) {
                stack.pop();
            }
        } else if ( cmd == "size" ) {
            cout << stack.size() << endl;
        } else if ( cmd == "empty" ) {
            cout << (stack.empty() ? 1 : 0) << endl;
        } else if ( cmd == "top" ) {
            cout << (stack.empty() ? -1 : stack.top()) << endl;
        }
    }

    return 0;
}