#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    int res = 0;
    for ( int i = 5; i <= n; i *= 5 ) {
        res += n / i;
    }
    cout << res << '\n';
    
    return 0;
}