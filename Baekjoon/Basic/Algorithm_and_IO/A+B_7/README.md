11021번 A+B - 7
--------------

출력 시에 문자열 "Case #"을 추가하여야합니다. 또한 case별로 index값을 붙여야 하기 때문에 for문이 적합하다고 생각합니다.

1. iostream 사용

~~~ cpp
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    for ( int i = 1; i <= tc; i++ ) {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << endl;
    }

    return 0;
}
~~~

2. cstdio 사용

~~~ cpp
#include <cstdio>

int main() {
    int tc;
    scanf("%d", &tc);

    for ( int i = 1; i <= tc; i++ ) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", i, a + b);
    }

    return 0;
}
~~~