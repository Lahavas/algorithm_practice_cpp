#include <cstdio>

#define MAX 100

int main() {

    char s[MAX];

    while ( fgets(s, sizeof(s), stdin) != NULL ) {
        printf("%s", s);
    }

    return 0;
}