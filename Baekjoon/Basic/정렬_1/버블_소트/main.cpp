#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<pair<int, int>> a(n);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    
    int res = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( res < a[i].second - i ) {
            res = a[i].second - i;
        }
    }
    
    cout << res + 1 << '\n';
    return 0;
}