#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    
    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        int x = (i <= n ? i : (n * 2) - i);
        
        for ( int j = 0; j < (n * 2) - 1; ++j ) {
            if ( j + x < n ) {
                cout << ' ';
            } else {
                for ( int k = 1; k <= (x * 2) - 1; ++k ) {
                    cout << '*';
                }
                cout << '\n';
                break;
            }   
        }
    }
    
    return 0;
}