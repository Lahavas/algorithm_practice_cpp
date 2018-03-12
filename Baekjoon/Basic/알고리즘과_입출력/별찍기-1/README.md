2438번 별찍기 - 1
---------------

직각삼각형 모양의 별을 찍는 문제입니다.  
별 혹은 줄띄우기와 같은 char 형식의 문자만 출력하면 되기 때문에 putchar 함수를 사용하는게 더욱 효율적일 수 있습니다.

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
        for ( int j = 1; j <= i; ++j ) {
            cout << "*";
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
        for ( int j = 1; j <= i; ++j ) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
~~~