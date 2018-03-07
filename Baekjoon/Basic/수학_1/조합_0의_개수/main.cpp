#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long two = 0, five = 0;
    long n = 0, m = 0;
    cin >> n >> m;
    
    for ( long i = 2; i <= n; i *= 2 ) {
        two += (n / i);
    }
    for ( long i = 2; i <= (n - m); i *= 2 ) {
        two -= ((n - m) / i);
    }
    for ( long i = 2; i <= m; i *= 2 ) {
        two -= (m / i);
    }
    
    for ( long i = 5; i <= n; i *= 5 ) {
        five += (n / i);
    }
    for ( long i = 5; i <= (n - m); i *= 5 ) {
        five -= ((n - m) / i);
    }
    for ( long i = 5; i <= m; i *= 5 ) {
        five -= (m / i);
    }
    
    cout << min(two, five) << endl;
    
    return 0;
}