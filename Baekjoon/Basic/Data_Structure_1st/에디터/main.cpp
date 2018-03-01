#include <cstdio>
#include <stack>

#define MAX 600000

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