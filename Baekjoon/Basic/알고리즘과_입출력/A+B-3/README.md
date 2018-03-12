10950번 A+B - 3
--------------

테스트 케이스의 갯수를 입력받아 반복문을 통해 문제를 해결할 수 있습니다.

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    while ( cnt-- ) {
        int a = 0, b = 0;
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

int main() 
{
    int cnt;
    scanf("%d", &cnt);

    while ( cnt-- ) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}
~~~