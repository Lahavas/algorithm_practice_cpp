#include <cstdio>

#define MAX 100

int main() {
    char s[MAX];

    while ( scanf("%[^\n]\n", s) == 1 ) {
        printf("%s\n", s);
    }

    return 0;
}