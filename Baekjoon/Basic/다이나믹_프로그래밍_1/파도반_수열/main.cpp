#include <iostream>

using namespace std;

constexpr int SIZE = 101;

long d[SIZE] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12 };

int main()
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;
    
    while ( cnt-- ) {
        int n = 0;
        cin >> n;
        
        for ( int i = 11; i <= n; ++i ) {
            d[i] = d[i - 1] + d[i - 5];
        }
        
        cout << d[n] << '\n';
    }
    
    return 0;
}