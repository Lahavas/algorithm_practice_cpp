#include <cstdio>
#include <cstring>

#define MAX 102

int main() {
    char s[MAX];
    scanf("%s", s);

    for ( int i = 'a' ; i <= 'z'; i++ ) {
        int index = -1;

        int len = strlen(s);

        for ( int j = 0; j < len; j++ ) {
            if ( i == s[j] ) {
                index = j;
                break;
            }
        }
        
        printf("%d ", index);
    }

    printf("\n");

    return 0;
}