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