1046번 에디터
-----------

커서를 이동시키고 문자를 추가 및 삭제하는 기능이 존재하므로, 일반적인 문자열과 커서 인덱스 값을 두는 것은 적합하지 않습니다.  
커서를 기준으로 왼쪽 문자열을 저장할 스택과 오른쪽 문자열을 저장할 스택, 총 두개의 스택을 이용하여 문제를 해결할 수 있습니다.  
결과를 출력할 때는 시작점은 왼쪽 문자열 스택의 bottom 부분이고, 도착점은 오른쪽 문자열 스택의 bottom 부분이므로 왼쪽 문자열 스택을 오른쪽 문자열 스택으로 이동시킨 뒤에 오른쪽 문자열 스택을 차례대로 출력하는 방법을 추천합니다.

1. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>
#include <stack>

using namespace std;

constexpr int MAX = 600000;

stack<char> ls;
stack<char> rs;

void updateEditor(char cmd) 
{
    switch ( cmd ) {
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
            scanf("%c", &input);
            getchar();

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
        printf("%c", rs.top());
        rs.pop();
    }

    putchar('\n');

    return;
}

int main() 
{
    char a[MAX] = { '\0' };
    scanf("%s", a);

    int cnt = 0;
    scanf("%d", &cnt);
    getchar();

    for ( int i = 0; i < MAX; ++i ) {
        if ( a[i] ) {
            ls.push(a[i]);
        } else {
            break;
        }
    }

    while ( cnt-- ) {
        char cmd = '\0';
        scanf("%c", &cmd);
        getchar();

        updateEditor(cmd);
    }

    printEditor();

    return 0;
}
~~~

2. iostream을 사용하여 입출력

~~~ cpp
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
~~~