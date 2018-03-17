2446번 별찍기 - 9
---------------

직각 이등변 삼각형 모양이 좌, 우, 대각선으로 대칭인 모양으로 별을 찍는 문제입니다.  
가로 길이는 2 * N - 1이며, N을 기준으로 상하가 대칭입니다.  
가로 길이 N까지는, 가로 좌표값이 세로 좌표값보다 작거나 같을 경우 별을 찍어주며, 이후에는 대칭으로 출력해주는 방법으로 문제를 해결할 수 있습니다.

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