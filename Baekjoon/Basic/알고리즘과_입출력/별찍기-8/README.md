2445번 별찍기 - 8
---------------

직각 이등변 삼각형 모양이 좌, 우, 대각선으로 대칭인 모양으로 별을 찍는 문제입니다.  
가로로 2 * N, 세로로 2 * N - 1 만큼의 길이를 가지며, 네 부분으로 나누어서 가로를 x, 세로를 y로 설정합니다.  
이후 x >= y일 경우에 별을 찍고 나머지를 공백으로 두어 문제를 풀 수 있습니다.  

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

        for ( int j = 1; j <= n * 2; ++j ) {
            int y = (j <= n ? j : (n * 2) - j + 1);

            if ( x >= y ) {
                cout << '*';
            } else {
                cout << ' ';
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

        for ( int j = 1; j <= n * 2; ++j ) {
            int y = (j <= n ? j : (n * 2) - j + 1);

            if ( x >= y ) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }

        putchar('\n');
    }

    return 0;
}
~~~