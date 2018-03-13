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