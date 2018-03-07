1000번 A+B
----------

1. iostream 사용

~~~ cpp
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    cout << a + b << endl;

    return 0;
}
~~~

2. cstdio 사용

~~~ cpp
#include <cstdio>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);

    return 0;
}
~~~