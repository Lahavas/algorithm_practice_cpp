2193번 이친수
-----------

D[N]은 N자리의 이친수로 정의할 수 있습니다.  
N번째 자리에 0이 오는 경우에는 D[N-1], N번째 자리에 1이 오는 경우에는 D[N-2] 입니다.  
즉, D[N] = D[N-1] + D[N-2] 라고 할 수 있습니다.  

다른 방법으로, D[N][L]은 마지막 자리의 수가 L인 N자리의 이친수로 정의할 수 있습니다.  
이 때, D[N][0] = D[N-1][0] + D[N-1][1] 이고, D[N][1] = D[N-1][0] 입니다.  

1. 일반적인 방법으로 풀이

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector<long> d(n + 1, 0); 

    for ( int i = 1; i <= n; ++i ) {
        if ( i == 1 ) {
            d[1] = 1;
        } else if ( i == 2 ) {
            d[2] = 1;
        } else {
            d[i] = d[i - 1] + d[i - 2];
        }
    }

    cout << d[n] << '\n';

    return 0;
}
~~~

2. N번째 숫자에 따라 다르게 저장해서 풀이

~~~ cpp
#include <cstdio>

constexpr int MAX = 91;

long d[MAX][2] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        if ( i == 1 ) {
            d[i][1] = 1;
            continue;
        } else if ( i == 2 ) {
            d[i][0] = 1;
            continue;
        }

        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }

    printf("%ld\n", d[n][0] + d[n][1]);

    return 0;
}
~~~