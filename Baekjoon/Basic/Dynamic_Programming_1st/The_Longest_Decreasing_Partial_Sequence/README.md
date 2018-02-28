11722번 가장 긴 감소하는 부분 수열
---------------------------

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
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
    
    cout << *max_element(d.begin(), d.end()) << endl;
    
    return 0;
}
~~~