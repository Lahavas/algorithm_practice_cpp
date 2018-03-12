10952번 A+B - 5
--------------

테스트 케이스가 존재하지 않는 대신 입력값이 0일 때 반복문을 빠져나오도록 설계해야합니다.

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int a = 0, b = 0;

    while ( true ) {
        cin >> a >> b;
        if ( a == 0 && b == 0 ) {
            break;
        } else {
            cout << a + b << '\n';
        }
    }

    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

int main() 
{
    int a = 0, b = 0;

    while ( true ) {
        scanf("%d %d", &a, &b);

        if ( a == 0 && b == 0 ) {
            break;
        } else {
            printf("%d\n", a + b);
        }
    }

    return 0;
}
~~~