#include <cstdio>

#define MAX 102

int main() {
    char s[MAX];
    scanf("%s", s);

    int len = 0;
    for ( int i = 0; i < MAX; i++ ) {
        if ( s[i] == '\0' ) {
            break;
        }
        len++;
    }
    
    printf("%d\n", len);

    return 0;
}