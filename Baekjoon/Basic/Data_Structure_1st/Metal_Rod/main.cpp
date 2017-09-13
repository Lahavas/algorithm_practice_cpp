#include <cstdio>

#define MAX 100001

int countRod(char* input) {
    int rod = 0;
    int result = 0;

    for ( int i = 0; i < MAX; i++ ) {
        if ( input[i] == '(' ) {
            if ( input[i + 1] == ')' ) {
                result += rod;
                i++;
            } else {
                rod++;
            }
        } else if ( input[i] == ')' ) {
            result++;
            rod--;
        } else {
            break;
        }
    } 

    return result;
}

int main() {
    char input[MAX];
    scanf("%s", input);

    printf("%d\n", countRod(input));

    return 0;
}