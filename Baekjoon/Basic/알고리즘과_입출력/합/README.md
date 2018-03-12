8393번 합
--------

1부터 N까지의 합을 구하는 문제입니다.  
주의할 점은 N이 굉장히 큰 숫자일 때, 지정한 자료형(예를 들면 int)을 초과할 수 있다는 점인데,  
해당 문제에서는 1 <= N <= 10000 이므로, N = 10000이더라도 500050, 즉 int 자료형 내에서 처리 가능합니다.

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int sum = 0;
    for ( int i = 1; i <= n; ++i ) {
        sum += i;
    }
    cout << sum << '\n';

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

    int sum = 0;
    for ( int i = 1; i <= n; ++i ) {
        sum += i;
    }
    printf("%d\n", sum);

    return 0;
}
~~~