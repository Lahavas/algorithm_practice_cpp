10992번 별찍기 - 17
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
            if ( t == 1 || t == (i * 2) - 1 ) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    
    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        cout << '*';
    }
    cout << '\n';

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

    for ( int i = 1; i < n; ++i ) {
        for ( int s = 1; s <= n - i; ++s ) {
            putchar(' ');
        }
        for ( int t = 1; t <= (i * 2) - 1; ++t ) {
            if ( t == 1 || t == (i * 2) - 1 ) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        putchar('*');
    }
    putchar('\n');

    return 0;
}
~~~