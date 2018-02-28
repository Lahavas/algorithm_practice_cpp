11054번 가장 긴 바이토닉 부분 수열
---------------------------

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
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

    int result = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( result < d_inc[i] + d_dec[i] - 1 ) {
            result = d_inc[i] + d_dec[i] - 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
~~~