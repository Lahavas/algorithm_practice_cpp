#include <cstdio>

#define MAX 101

int main() {
    char input[MAX];

    while ( scanf("%[^\n]\n", input) != EOF ) {
        printf("%s\n", input);
    }

    return 0;
}