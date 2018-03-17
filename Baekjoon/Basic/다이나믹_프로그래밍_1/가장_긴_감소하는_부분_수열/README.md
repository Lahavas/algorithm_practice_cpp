11722번 가장 긴 감소하는 부분 수열
---------------------------

D[N]을 A[N]을 마지막으로 하는 가장 긴 감소하는 부분 수열의 길이라고 정의할 수 있습니다.  
D[N] = max(D[1], ..., D[M], ... , D[N - 1]) + 1, (A[N] < A[M]) 이라고 할 수 있습니다.

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<int> a(n, 0);
    vector<int> d(n, 0);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    
    for ( int i = 0; i < n; ++i ) {
        d[i] = 1;
        for ( int j = 0; j < i; ++j ) {
            if ( a[i] < a[j] && d[i] < d[j] + 1 ) {
                d[i] = d[j] + 1;
            }
        }
    }
    
    cout << *max_element(d.begin(), d.end()) << '\n';
    
    return 0;
}
~~~