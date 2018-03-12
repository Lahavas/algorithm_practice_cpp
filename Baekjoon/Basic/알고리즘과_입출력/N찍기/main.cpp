#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    
    for ( int i = 1; i <= n; ++i ) {
        cout << n << '\n';
    }
    
    return 0;
}