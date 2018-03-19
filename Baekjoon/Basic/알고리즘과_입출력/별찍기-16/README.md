10991번 별찍기 - 16
-----------------

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 1; i <= n; ++i ) {
        for ( int s = 1; s <= n - i; ++s ) {
            cout << ' ';
        }
        for ( int t = 1; t <= (i * 2) - 1; ++t ) {
            if ( t % 2 == 0 ) {
                cout << ' ';
            } else {
                cout << '*';
            }
        }
        cout << '\n';
    }

    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        for ( int s = 1; s <= n - i; ++s ) {
            putchar(' ');
        }
        for ( int t = 1; t <= (i * 2) - 1; ++t ) {
            if ( t % 2 == 0 ) {
                putchar(' ');
            } else {
                putchar('*');
            }
        }
        putchar('\n');
    }

    return 0;
}
~~~