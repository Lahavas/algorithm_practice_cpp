#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> ls;
stack<char> rs;

void initEditor(string s)
{
    for ( auto c : s ) {
        ls.push(c);
    }

    return;
}

void updateEditor(char cmd) 
{
    switch (cmd) {
        case 'L':
            if ( !ls.empty() ) {
                rs.push(ls.top());
                ls.pop();
            }
            break;
        case 'D':
            if ( !rs.empty() ) {
                ls.push(rs.top());
                rs.pop();
            }
            break;
            case 'B':
            if ( !ls.empty() ) {
                ls.pop();
            }
            break;
        case 'P': {
            char input = '\0';
            cin >> input;

            ls.push(input);
            break;
        }
        default:
            break;
    }

    return;
}

void printEditor()
{
    while ( !ls.empty() ) {
        rs.push(ls.top());
        ls.pop();
    }

    while ( !rs.empty() ) {
        cout << rs.top();
        rs.pop();
    }

    cout << '\n';

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    initEditor(s);

    int cnt = 0;
    cin >> cnt;

    while ( cnt-- ) {
        char cmd = '\0';
        cin >> cmd;

        updateEditor(cmd);
    }

    printEditor();

    return 0;
}