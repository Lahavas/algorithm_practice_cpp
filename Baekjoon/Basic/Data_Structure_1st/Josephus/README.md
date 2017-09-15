1158번 조세퍼스 문제
----------------

Queue를 사용하여 1부터 m까지의 정수를 push합니다.  
이후에 n번째 이전까지는 front의 값을 push하고, 이후 해당 값을 pop하면서 front가 back으로 이동하도록 만들고,  
n번째에서는 front 값을 pop합니다. 이와 같은 과정을 Queue가 empty가 나올 때까지 반복하면 문제가 해결됩니다.

~~~ cpp
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
~~~