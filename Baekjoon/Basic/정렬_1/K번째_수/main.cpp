#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    int k = 0;
    cin >> n >> k;
    k -= 1;
    
    vector<long> a(n, 0);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    
    nth_element(a.begin(), a.begin() + k, a.end());
    cout << a[k] << '\n';
    
    return 0;
}