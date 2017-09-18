1046번 에디터
-----------

커서를 이동시키고 문자를 추가 및 삭제하는 기능이 존재하므로, 일반적인 문자열과 커서 인덱스 값을 두는 것은 적합하지 않습니다.  
커서를 기준으로 왼쪽 문자열을 저장할 스택과 오른쪽 문자열을 저장할 스택, 총 두개의 스택을 이용하여 문제를 해결할 수 있습니다.  
결과를 출력할 때는 시작점은 왼쪽 문자열 스택의 bottom 부분이고, 도착점은 오른쪽 문자열 스택의 bottom 부분이므로 왼쪽 문자열 스택을 오른쪽 문자열 스택으로 이동시킨 뒤에 오른쪽 문자열 스택을 차례대로 출력하는 방법을 추천합니다.

~~~ cpp
#include <cstdio>
#include <stack>

#define MAX 600001

std::stack<char> lst;
std::stack<char> rst;

void updateEditor(char cmd) {
    switch ( cmd ) {
        case 'L':
            if ( !lst.empty() ) {
                rst.push(lst.top());
                lst.pop();
            }
            break;
        case 'D':
            if ( !rst.empty() ) {
                lst.push(rst.top());
                rst.pop();
            }
            break;
        case 'B':
            if ( !lst.empty() ) {
                lst.pop();
            }
            break;
        case 'P':
            char input;
            scanf("%c", &input);
            getchar();

            lst.push(input);
            break;
        default:
            break;
    }

    return;
}

void printEditor() {
    while ( !lst.empty() ) {
        rst.push(lst.top());
        lst.pop();
    }

    while ( !rst.empty() ) {
        printf("%c", rst.top());
        rst.pop();
    }

    puts("");

    return;
}

int main() {
    char s[MAX];
    scanf("%s", s);

    int tc;
    scanf("%d", &tc);
    getchar();

    for ( int i = 0; i < MAX; i++ ) {
        if ( s[i] ) {
            lst.push(s[i]);
        } else {
            break;
        }
    }

    while ( tc-- ) {
        char cmd;
        scanf("%c", &cmd);
        getchar();

        updateEditor(cmd);
    }

    printEditor();

    return 0;
}
~~~