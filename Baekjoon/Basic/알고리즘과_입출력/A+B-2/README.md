2558번 A+B - 2
--------------

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int a = 0, b = 0;
    cin >> a >> b;
    cout << a + b << '\n';

    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

int main() 
{
    int a = 0, b = 0;
    scanf("%d\n%d", &a, &b);
    printf("%d\n", a + b);

    return 0;
}
~~~