#include <cstdio>
#include <queue>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    std::queue<int> q;

    for ( int i = 1; i <= m; i++ ) {
        q.push(i);
    }

    printf("<");

    while ( !q.empty() ) {
        for ( int i = 1; i <= n; i++ ) {
            if ( i == n ) {
                printf("%d", q.front());
                q.pop();
            } else {
                q.push(q.front());
                q.pop();
            }
        }

        if ( q.size() != 0 ) {
            printf(", ");
        }
    }

    printf(">\n");

    return 0;
}