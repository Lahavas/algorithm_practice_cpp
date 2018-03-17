9465번 스티커
-----------

D[N][S]은 2XN 모양의 스티커일 경우 최대 점수라고 정의할 수 있으며,  
S이 0이면 N번째 스티커를 때지 않은 상태의 최댓값,  
S이 1이면 첫번째 스티커를 땐 상태의 최댓값,  
S이 2이면 두번째 스티커를 땐 상태의 최댓값이라고 생각할 수 있습니다.  
D[N][0] = max(D[N-1][0], D[N-1][1], D[N-1][2])이고,  
D[N][1] = max(D[N-1][0], D[N-1][2]) + A[N][1]이며,  
D[N][2] = max(D[N-1][0], D[N-1][1]) + A[N][2]임을 알 수 있습니다.

~~~ cpp
#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX = 100001;

int main()
{
    int cnt = 0;
    scanf("%d", &cnt);
    
    while ( cnt-- ) {
        int a[MAX][3] = { 0 };
        int d[MAX][3] = { 0 };

        int n = 0;
        scanf("%d", &n);
        
        for ( int i = 1; i <= n; ++i ) {
            scanf("%d", &a[i][1]);
        }

        for ( int i = 1; i <= n; ++i ) {
            scanf("%d", &a[i][2]);
        }
        
        for ( int i = 1; i <= n; ++i ) {
            d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
            d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][1];
            d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][2];
        }
        
        int res = max(d[n][0], max(d[n][1], d[n][2]));
        printf("%d\n", res);
    }
    
    return 0;
}
~~~