#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    
    vector<int> a(n, 0);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for ( auto p : a ) {
        cout << p << '\n';
    }
    
    return 0;
}