#include <cstdio>
#include <cstring>

#define MAX 100

int main() {
    char input[MAX];
    scanf("%s", input);

    for ( int i = 'a' ; i <= 'z'; i++ ) {
        int index = -1;

        for ( int j = 0; j < strlen(input); j++ ) {
            if ( i == input[j] ) {
                index = j;
                break;
            }
        }
        
        printf("%d ", index);
    }

    printf("\n");

    return 0;
}