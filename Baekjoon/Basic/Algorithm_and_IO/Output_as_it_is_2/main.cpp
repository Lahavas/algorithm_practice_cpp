#include <cstdio>

#define MAX 101

int main() {

    char input[MAX];

    while ( fgets(input, sizeof(input), stdin) != NULL ) {
        printf("%s", input);
    }

    return 0;
}