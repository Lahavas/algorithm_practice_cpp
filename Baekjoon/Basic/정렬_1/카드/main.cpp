#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<long long> a(n, 0);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long max = a[0];
    int max_cnt = 1;
    int cnt = 1;
    
    for ( int i = 1; i < n; ++i ) {
        if ( a[i] == a[i - 1] ) {
            ++cnt;
        } else {
            cnt = 1;
        }
        
        if ( max_cnt < cnt ) {
            max_cnt = cnt;
            max = a[i];
        }
    }
    
    cout << max << '\n';
    
    return 0;
}