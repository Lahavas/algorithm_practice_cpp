2446번 별찍기 - 9
---------------

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        int x = (i <= n ? i : (n * 2) - i);

        for ( int j = 1; j <= (n * 2) - 1; ++j ) {
            if ( x > j ) {
                cout << ' ';
            } else {
                for ( int k = 1; k <= ((n - x) * 2) + 1 ; ++k ) {
                    cout << '*';
                }
                break;
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

    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        int x = (i <= n ? i : (n * 2) - i);

        for ( int j = 1; j <= (n * 2) - 1; ++j ) {
            if ( x > j ) {
                putchar(' ');
            } else {
                for ( int k = 1; k <= ((n - x) * 2) + 1; ++k ) {
                    putchar('*');
                }
                break;
            }
        }
        putchar('\n');
    }

    return 0;
}
~~~