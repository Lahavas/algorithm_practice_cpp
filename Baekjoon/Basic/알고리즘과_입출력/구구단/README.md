2739번 구구단
-----------

구구단 N단을 출력하는 문제입니다.  

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 1; i <= 9; ++i ) {
        cout << n << " * " << i << " = " << n * i << "\n";
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

    for ( int i = 1; i <= 9; ++i ) {
        printf("%d * %d = %d\n", n, i, n * i);
    }

    return 0;
}
~~~