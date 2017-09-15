#include <cstdio>
#include <queue>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    std::queue<int> queue;

    for ( int i = 1; i <= m; i++ ) {
        queue.push(i);
    }

    printf("<");

    while ( !queue.empty() ) {
        for ( int i = 1; i <= n; i++ ) {
            if ( i == n ) {
                printf("%d", queue.front());
                queue.pop();
            } else {
                queue.push(queue.front());
                queue.pop();
            }
        }

        if ( queue.size() != 0 ) {
            printf(", ");
        }
    }

    printf(">\n");

    return 0;
}