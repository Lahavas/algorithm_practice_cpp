10950번 A+B - 3
--------------

테스트 케이스를 입력받아 반복문을 통해 문제를 해결할 수 있습니다.

1. iostream 사용

~~~ cpp
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int cnt;
    cin >> cnt;

    while (cnt--) {
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}
~~~

2. cstdio 사용

~~~ cpp
#include <cstdio>

int main() {
    int cnt;
    scanf("%d", &cnt);

    while (cnt--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}
~~~