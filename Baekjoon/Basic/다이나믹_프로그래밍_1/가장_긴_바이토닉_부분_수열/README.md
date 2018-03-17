11054번 가장 긴 바이토닉 부분 수열
---------------------------

A[1]부터 A[N]까지 존재할 때, D_INC[i]는 A[i]까지의 가장 긴 증가하는 부분 수열의 길이이고 D_DEC[i]는 A[i]부터 A[N]까지의 가장 긴 감소하는 부분 수열이라고 정의할 수 있습니다.  
이 때 가장 긴 바이토닉 부분 수열은 max(D_INC[1] + D_DEC[1] - 1, ..., D_INC[N] + D_DEC[N] - 1)이라고 할 수 있습니다.

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<int> a(n, 0);
    vector<int> d_inc(n, 0);
    vector<int> d_dec(n, 0);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    
    for ( int i = 0; i < n; ++i ) {
        d_inc[i] = 1;
        for ( int j = 0; j < i; ++j ) {
            if ( a[i] > a[j] && d_inc[i] < d_inc[j] + 1 ) {
                d_inc[i] = d_inc[j] + 1;
            }
        }
    }

    for ( int i = n - 1; i >= 0; --i ) {
        d_dec[i] = 1;
        for ( int j = i + 1; j < n; ++j ) {
            if ( a[i] > a[j] && d_dec[i] < d_dec[j] + 1 ) {
                d_dec[i] = d_dec[j] + 1;
            }
        }
    }

    int res = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( res < d_inc[i] + d_dec[i] - 1 ) {
            res = d_inc[i] + d_dec[i] - 1;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
~~~