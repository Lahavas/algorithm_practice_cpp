#include <cstdio>
#include <queue>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    std::queue<int> qu;

    for ( int i = 1; i <= m; i++ ) {
        qu.push(i);
    }

    printf("<");

    while ( !qu.empty() ) {
        for ( int i = 1; i <= n; i++ ) {
            if ( i == n ) {
                printf("%d", qu.front());
                qu.pop();
            } else {
                qu.push(qu.front());
                qu.pop();
            }
        }

        if ( qu.size() != 0 ) {
            printf(", ");
        }
    }

    printf(">\n");

    return 0;
}