#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if ( b == 0 ) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    int cnt = 0;
    cin >> cnt;
    
    while ( cnt-- ) {
        int n = 0;
        cin >> n;
        
        vector<long> a(n, 0);
        
        for ( int i = 0; i < n; ++i ){
            cin >> a[i];
        }
        
        long sum = 0;
        for ( int i = 0; i < n - 1; ++i ) {
            for ( int j = i + 1; j < n; ++j ) {
                sum += gcd(a[i], a[j]);
            }
        }
        cout << sum << endl;
    }
    
    return 0;
}