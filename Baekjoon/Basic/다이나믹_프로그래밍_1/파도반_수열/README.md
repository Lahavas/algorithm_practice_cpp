9461번 파도반 수열
---------------

해당 문제는 그림을 보고 규칙을 찾아 문제를 해결할 수 있습니다.  
D[N] = D[N-1] + D[N-5], (N >= 11) 이라고 할 수 있습니다.

~~~ cpp
#include <iostream>

using namespace std;

constexpr int size = 101;

long d[size] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12 };

int main()
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;
    
    while ( cnt-- ) {
        int n = 0;
        cin >> n;
        
        for ( int i = 11; i <= n; ++i ) {
            d[i] = d[i - 1] + d[i - 5];
        }
        
        cout << d[n] << '\n';
    }
    
    return 0;
}
~~~