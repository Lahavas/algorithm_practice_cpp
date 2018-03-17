1912번 연속합
-----------

D[N]은 A[N]으로 끝나는 최대 연속합으로 정의할 수 있습니다.  
D[N] = max(A[N], D[N-1] + A[N]) 이며,  
결과는 max(D[1], ..., D[N]) 입니다.

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    long n = 0;
    cin >> n;
    
    vector<int> a(n, 0);
    vector<int> d(n, 0);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    
    for ( int i = 0; i < n; ++i ) {
        d[i] = a[i];
        if ( i == 0 ) {
            continue;
        }
        
        if ( d[i] < d[i - 1] + a[i] ) {
            d[i] = d[i - 1] + a[i];
        }
    }
    
    cout << *max_element(d.begin(), d.end()) << '\n';
    
    return 0;
}
~~~