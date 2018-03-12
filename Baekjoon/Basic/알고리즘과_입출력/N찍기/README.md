2741번 N찍기
----------

1. iostream header를 사용하여 입출력하기

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    
    for ( int i = 1; i <= n; ++i ) {
        cout << i << '\n';
    }
    
    return 0;
}
~~~

2. cstdio header를 사용하여 입출력하기

~~~ cpp
#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        printf("%d\n", i);
    }

    return 0;
}
~~~