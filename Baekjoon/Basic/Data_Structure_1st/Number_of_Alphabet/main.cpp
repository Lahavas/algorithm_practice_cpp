#include <cstdio>
#include <cstring>

#define MAX 102

int main() {
    char s[MAX];
    scanf("%s", s);

    for ( int i = 'a'; i <= 'z'; i++) {
        int cnt = 0;

        int len = strlen(s);

        for ( int j = 0; j < len; j++ ) {
            if ( i == s[j] ) {
                cnt++;
            }
        }

        printf("%d ", cnt);
    }

    printf("\n");

    return 0;
}