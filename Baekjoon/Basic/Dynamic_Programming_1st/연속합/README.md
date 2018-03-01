1912번 연속합
-----------

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long n = 0;
    cin >> n;
    
    vector<int> a(n, 0);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    
    vector<int> d(n, 0);
    
    for ( int i = 0; i < n; ++i ) {
        d[i] = a[i];
        if ( i == 0 ) {
            continue;
        }
        
        if ( d[i] < d[i - 1] + a[i] ) {
            d[i] = d[i - 1] + a[i];
        }
    }
    
    cout << *max_element(d.begin(), d.end()) << endl;
    
    return 0;
}
~~~