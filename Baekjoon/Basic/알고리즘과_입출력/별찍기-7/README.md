2444번 별찍기 - 7
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

        for ( int s = 1; s <= n - x; ++s ) {
            cout << ' ';
        }
        for ( int t = 1; t <= (x * 2) - 1; ++t ) {
            cout << '*';
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

        for ( int s = 1; s <= n - x; ++s ) {
            putchar(' ');
        }
        for ( int t = 1; t <= (x * 2) - 1; ++t ) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
~~~