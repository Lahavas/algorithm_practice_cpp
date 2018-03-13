2442번 별찍기 - 5
---------------

이등변 삼각형 모양의 별을 찍는 문제입니다.  
x좌표와 y좌표의 합이 입력값 N보다 1이 큰 시점부터 (x * 2) - 1개의 별이 찍히므로,  
삼중 for문을 사용하여 문제를 해결할 수 있습니다.

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