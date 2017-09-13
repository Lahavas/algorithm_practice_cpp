#include <cstdio>

#define MAX 51

bool isValid(char* ps) {
    int cnt = 0;

    for ( int i = 0; i < MAX; i++ ) {
        if ( ps[i] == '(' ) {
            cnt++;
        } else if ( ps[i] == ')' ) {
            cnt--;
        } else {
            break;
        }

        if ( cnt < 0 ) {
            return false;
        }
    }

    return (cnt == 0 ? true : false);
}

int main() {
    int test_case;
    scanf("%d", &test_case);

    char ps[MAX];

    while ( test_case-- ) {
        scanf("%s", ps);

        if ( isValid(ps) == true ) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}