#include <cstdio>

#define MAX 100

int main() {
    char input[MAX];
    scanf("%s", input);

    int length = 0;
    for ( int i = 0; i < MAX; i++ ) {
        if ( input[i] == '\0' ) {
            break;
        }
        length++;
    }
    
    printf("%d\n", length);

    return 0;
}