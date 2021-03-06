11055번 가장 큰 증가 부분 수열
------------------------

D[N]을 A[N]을 마지막으로 하는 가장 큰 증가 부분 수열의 크기라고 정의할 수 있습니다.  
D[N] = max(D[1] + A[N], ..., D[M] + A[N], ... , D[N - 1] + A[N]) + A[N], (A[N] > A[M]) 이라고 할 수 있습니다.

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
        d[i] = a[i];
        for ( int j = 0; j < i; ++j ) {
            if ( a[j] < a[i] && d[i] < d[j] + a[i] ) {
                d[i] = d[j] + a[i];
            }
        }
    }
    
    cout << *max_element(d.begin(), d.end()) << '\n';
    
    return 0;
}
~~~