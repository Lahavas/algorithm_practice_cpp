2579번 계단 오르기
---------------

D[N][S]은 N번째 계단을 오를 때의 점수의 최댓값이며, S가 1이면 한 번 연속으로 계단을 밟아야 하는 경우, S가 2이면 두 번 연속으로 계단을 밟아야 하는 경우입니다.  
S가 0인 경우는 조건상에서 N번째 계단은 반드시 밟아야하기 때문에 불가능함을 알 수 있습니다.  
D[N][1] = max(D[N-2][1], D[N-2][2]) + A[N] 이며,  
D[N][2] = D[N-1][1] + A[N] 입니다.  

다른 방법으로는, D[N]은 N번째 계단을 올라갔을 때, 최대 점수로 정의할 수 있습니다.  
이 때, D[N] = max(D[N-2] + A[N], D[N-3] + A[N-1] + A[N]) 이라고 할 수 있습니다.

1. 일반적인 방법으로 푸는 경우

~~~ cpp
#include <iostream>
#include <vector>
#include <algorithm>

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
        d[i] = max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]);
    }

    cout << d[n] << '\n';

    return 0;
}
~~~

2. 상태를 저장하는 경우

~~~ cpp
#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX = 301;

int a[MAX] = { 0 };
long d[MAX][3] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    for ( int i = 1; i <= n; ++i ) {
        scanf("%d", &a[i]);
    }
    
    d[1][1] = a[1];
    
    for ( int i = 2; i <= n; ++i ) {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + a[i];
        d[i][2] = d[i - 1][1] + a[i];
    }
    
    printf("%d\n", max(d[n][1], d[n][2]));
    
    return 0;
}
~~~