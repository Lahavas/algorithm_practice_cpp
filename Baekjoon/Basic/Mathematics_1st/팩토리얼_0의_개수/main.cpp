#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    
    int res = 0;
    for ( int i = 5; i <= n; i *= 5 ) {
        res += n / i;
    }
    cout << res << endl;
    
    return 0;
}