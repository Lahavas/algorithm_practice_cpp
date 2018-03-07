#include <cstdio>

#define MAX 50

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
    int tc;
    scanf("%d", &tc);

    char ps[MAX];

    while ( tc-- ) {
        scanf("%s", ps);

        if ( isValid(ps) == true ) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}