2439번 별찍기 - 2
---------------

1. iostream header를 이용하여 입출력

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
            if ( j <= n - i ) {
                cout << " ";
            } else {
                cout << "*";
            }
        }

        cout << "\n";
    }

    return 0;
}
~~~

2. cstdio header의 putchar Function을 이용하여 출력

~~~ cpp
#include <iostream>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= n; ++j ) {
            if ( j <= n - i ) {
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