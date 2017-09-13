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