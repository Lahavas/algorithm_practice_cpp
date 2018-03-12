2742번 기찍 N
------------

N부터 1까지 각 Line에 출력하는 문제입니다.  
for문을 사용하여 각 인덱스를 출력하여 문제를 해결할 수 있습니다.

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = n; i >= 1; --i ) {
        cout << i << '\n';
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

    for ( int i = n; i >= 1; --i ) {
        printf("%d\n", i);
    }

    return 0;
}
~~~