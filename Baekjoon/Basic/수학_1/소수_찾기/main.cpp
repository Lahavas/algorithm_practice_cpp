#include <iostream>

using namespace std;

bool prime(int n) 
{
    if ( n < 2 ) {
        return false;
    }
    
    for ( int i = 2; i * i <= n; ++i ) {
        if ( n % i == 0 ) {
            return false;
        }
    }
    
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;
    
    int res = 0;

    while ( cnt-- ) {
        int n = 0;
        cin >> n;
        if ( prime(n) == true ) {
            ++res;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}