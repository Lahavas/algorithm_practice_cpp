2442번 별찍기 - 5
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

    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= n; ++j ) {
            if ( i + j <= n ) {
                cout << " ";
            } else {
                for ( int k = 1; k <= (i * 2) - 1; ++k ) {
                    cout << "*";
                }
                break;
            }
        }
        cout << "\n";
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
        for ( int j = 1; j <= n; ++j ) {
            if ( i + j <= n ) {
                putchar(' ');
            } else {
                for ( int k = 1; k <= (i * 2) - 1; ++k ) {
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