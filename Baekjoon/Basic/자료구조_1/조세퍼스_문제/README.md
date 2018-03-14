1158번 조세퍼스 문제
----------------

Queue를 사용하여 1부터 m까지의 정수를 push합니다.  
이후에 n번째 이전까지는 front의 값을 push하고, 이후 해당 값을 pop하면서 front가 back으로 이동하도록 만들고,  
n번째에서는 front 값을 pop합니다. 이와 같은 과정을 Queue가 empty가 나올 때까지 반복하면 문제가 해결됩니다.

1. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>
#include <queue>

using namespace std;

int main() 
{
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);

    queue<int> q;

    for ( int i = 1; i <= m; ++i ) {
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
~~~

2. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int m = 0, n = 0;
    cin >> m >> n;

    queue<int> q;

    for ( int i = 1; i <= m; ++i ) {
        q.push(i);
    }

    cout << '<';

    while ( !q.empty() ) {
        for ( int i = 1; i <= n; ++i ) {
            if ( i == n ) {
                cout << q.front();
                q.pop();
            } else {
                q.push(q.front());
                q.pop();
            }
        }

        if ( q.size() != 0 ) {
            cout << ", ";
        }
    }

    cout << '>' << '\n';

    return 0;
}
~~~