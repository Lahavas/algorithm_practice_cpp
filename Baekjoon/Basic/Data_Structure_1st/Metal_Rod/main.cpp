#include <cstdio>

#define MAX 100001

int countRod(char* s) {
    int rod = 0;
    int result = 0;

    for ( int i = 0; i < MAX; i++ ) {
        if ( s[i] == '(' ) {
            if ( s[i + 1] == ')' ) {
                result += rod;
                i++;
            } else {
                rod++;
            }
        } else if ( s[i] == ')' ) {
            result++;
            rod--;
        } else {
            break;
        }
    } 

    return result;
}

int main() {
    char s[MAX];
    scanf("%s", s);

    printf("%d\n", countRod(s));

    return 0;
}