#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    long long res = 1;
    for ( int i = 1; i <= n; ++i ) {
        res *= i;
    }
    
    cout << res << '\n';
    
    return 0;
}