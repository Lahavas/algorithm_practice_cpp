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
        if ( d[i] < 0 ) {
            continue;
        }
        
        for ( int j = i - 1; j >= 0; --j ) {
            if ( a[j] >= 0 ) {
                d[i] += a[j];
            } else {
                break;
            }
        }
        
        for ( int j = i + 1; j < n; ++j ) {
            if ( a[j] >= 0 ) {
                d[i] += a[j];
            } else {
                break;
            }
        }
    }
    
    cout << *max_element(d.begin(), d.end()) << endl;
    
    return 0;
}