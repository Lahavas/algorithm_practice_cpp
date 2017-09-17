1046번 에디터
-----------

커서를 이동시키고 문자를 추가 및 삭제하는 기능이 존재하므로, 일반적인 문자열과 커서 인덱스 값을 두는 것은 적합하지 않습니다.  
커서를 기준으로 왼쪽 문자열을 저장할 스택과 오른쪽 문자열을 저장할 스택, 총 두개의 스택을 이용하여 문제를 해결할 수 있습니다.  
결과를 출력할 때는 시작점은 왼쪽 문자열 스택의 bottom 부분이고, 도착점은 오른쪽 문자열 스택의 bottom 부분이므로 왼쪽 문자열 스택을 오른쪽 문자열 스택으로 이동시킨 뒤에 오른쪽 문자열 스택을 차례대로 출력하는 방법을 추천합니다.

~~~ cpp
#include <cstdio>
#include <stack>

#define MAX 600001

std::stack<char> left_stack;
std::stack<char> right_stack;

void updateEditor(char cmd) {
    switch ( cmd ) {
        case 'L':
            if ( !left_stack.empty() ) {
                right_stack.push(left_stack.top());
                left_stack.pop();
            }
            break;
        case 'D':
            if ( !right_stack.empty() ) {
                left_stack.push(right_stack.top());
                right_stack.pop();
            }
            break;
        case 'B':
            if ( !left_stack.empty() ) {
                left_stack.pop();
            }
            break;
        case 'P':
            char input;
            scanf("%c", &input);
            getchar();

            left_stack.push(input);
            break;
        default:
            break;
    }

    return;
}

void printEditor() {
    while ( !left_stack.empty() ) {
        right_stack.push(left_stack.top());
        left_stack.pop();
    }

    while ( !right_stack.empty() ) {
        printf("%c", right_stack.top());
        right_stack.pop();
    }

    puts("");

    return;
}

int main() {
    char init_string[MAX];
    scanf("%s", init_string);

    int test_case;
    scanf("%d", &test_case);
    getchar();

    for ( int i = 0; i < MAX; i++ ) {
        if ( init_string[i] ) {
            left_stack.push(init_string[i]);
        } else {
            break;
        }
    }

    while ( test_case-- ) {
        char cmd;
        scanf("%c", &cmd);
        getchar();

        updateEditor(cmd);
    }

    printEditor();

    return 0;
}
~~~