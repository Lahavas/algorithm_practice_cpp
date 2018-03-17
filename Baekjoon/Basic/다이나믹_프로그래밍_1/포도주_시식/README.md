2156번 포도주 시식
---------------

D[N][L]은 N개의 포도주 잔을 마실 수 있는 최대값이며, L번 연속으로 마실 경우라고 정의할 수 있습니다.  
D[N][0] = max(D[N-1][0], D[N-1][1], D[N-1][2]),  
D[N][1] = D[N-1][0] + A[N],  
D[N][2] = D[N-2][1] + A[N] 이라고 할 수 있습니다.   
다른 방법으로는, D[N]은 N개의 포도주 잔을 규칙에 따라 마실수 있는 최대값으로 정의할 수 있습니다.  
0번 연속으로 마실 경우에는 D[N] = D[N-1]이며,  
1번 연속으로 마실 경우에는 D[N] = A[N-2] + A[N]이고,  
2번 연속으로 마실 경우에는 D[N] = D[N-3] + A[N-1] + A[N]이라고 할 수 있습니다.  
즉, D[N] = max(D[N-1], D[N-2] + A[N], D[N-3] + D[N-1] + A[N]) 이라고 할 수 있습니다.

1. 일반적인 방법으로 푸는 경우

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector<int> a(n + 1, 0);
    vector<int> d(n + 1, 0);

    for ( int i = 1; i <= n; ++i ) {
        cin >> a[i];
    }

    d[1] = a[1];
    d[2] = a[1] + a[2];

    for ( int i = 3; i <= n; ++i ) {
        d[i] = d[i - 1];
        
        if ( d[i] < d[i - 2] + a[i] ) {
            d[i] = d[i - 2] + a[i];
        }
        
        if ( d[i] < d[i - 3] + a[i - 1] + a[i] ) {
            d[i] = d[i - 3] + a[i - 1] + a[i];
        }
    }

    cout << d[n] << '\n';

    return 0;
}
~~~

2. 상태를 정의하여 풀이하는 경우

~~~ cpp
#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX = 10001;

int a[MAX] = { 0 };
int d[MAX][3] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; ++i ) {
        scanf("%d", &a[i]);
    }

    d[1][1] = a[1];
    d[2][0] = a[1];
    d[2][1] = a[2];
    d[2][2] = a[1] + a[2];

    for ( int i = 3; i <= n; ++i ) {
        d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
        d[i][1] = d[i - 1][0] + a[i];
        d[i][2] = d[i - 1][1] + a[i];
    }

    int res = max(d[n][0], max(d[n][1], d[n][2]));
    printf("%d\n", res);

    return 0;
}
~~~