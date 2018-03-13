#include <cstdio>
#include <cstring>

constexpr int MAX = 100000;

int countRod(char *s) 
{
    int rod = 0;
    int result = 0;

    for ( int i = 0; i < strlen(s); ++i ) {
        if ( s[i] == '(' ) {
            if ( s[i + 1] == ')' ) {
                result += rod;
                i += 1;
            } else {
                rod += 1;
            }
        } else if ( s[i] == ')' ) {
            result += 1;
            rod -= 1;
        } else {
            break;
        }
    } 

    return result;
}

int main() 
{
    char s[MAX] = { NULL };
    scanf("%s", s);

    printf("%d\n", countRod(s));

    return 0;
}