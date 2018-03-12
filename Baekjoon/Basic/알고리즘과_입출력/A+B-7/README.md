11021번 A+B - 7
--------------

출력 시에 문자열 "Case #"을 추가하여야합니다. 또한 case별로 index값을 붙여야 하기 때문에 for문을 사용하는것이 적합합니다.

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    for ( int i = 1; i <= cnt; ++i ) {
        int a = 0, b = 0;
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << '\n';
    }

    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

int main() 
{
    int cnt = 0;
    scanf("%d", &cnt);

    for ( int i = 1; i <= cnt; ++i ) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", i, a + b);
    }

    return 0;
}
~~~