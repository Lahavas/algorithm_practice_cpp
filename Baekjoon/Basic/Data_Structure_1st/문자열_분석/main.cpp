#include <cstdio>
#include <cstring>

#define MAX 102

int main() {
    char s[MAX];

    while ( fgets(s, sizeof(s), stdin) != NULL ) {
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;

        int len = strlen(s);

        for ( int i = 0; i < len; i++ ) {
            if ( s[i] >= 'a' && s[i] <= 'z' ) {
                lower++;
            } else if ( s[i] >= 'A' && s[i] <= 'Z' ) {
                upper++;
            } else if ( s[i] >= '0' && s[i] <= '9' ) {
                number++;
            } else if ( s[i] == ' ' ) {
                space++;
            }
        }

        printf("%d %d %d %d\n", lower, upper, number, space);
    }

    return 0;
}