11655번 ROT13
-------------

~~~ cpp
#include <cstdio>
#include <cstring>

#define MAX 102

char ROT13(char c) {
    if ( c >= 'a' && c <= 'm' ) {
        return c + 13;
    } else if ( c >= 'n' && c <= 'z' ) {
        return c - 13;
    } else if ( c >= 'A' && c <= 'M' ) {
        return c + 13;
    } else if ( c >= 'N' && c <= 'Z' ) {
        return c - 13;
    } else {
        return c;
    }
}

int main() {
    char input[MAX];
    fgets(input, sizeof(input), stdin);

    for ( int i = 0; i < strlen(input); i++ ) {
        input[i] = ROT13(input[i]);
    }

    printf("%s\n", input);

    return 0;
}
~~~