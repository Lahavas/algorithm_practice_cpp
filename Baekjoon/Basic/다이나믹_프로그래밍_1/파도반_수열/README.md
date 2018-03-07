9461번 파도반 수열
---------------

~~~ cpp
#include <iostream>

using namespace std;

constexpr int size = 101;

long d[size] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12 };

int main()
{
    int cnt = 0;
    cin >> cnt;
    
    while ( cnt-- ) {
        int n = 0;
        cin >> n;
        
        for ( int i = 11; i <= n; ++i ) {
            d[i] = d[i - 1] + d[i - 5];
        }
        
        cout << d[n] << endl;
    }
    
    return 0;
}
~~~