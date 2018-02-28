#include <iostream>

using namespace std;

constexpr int maxSize = 301;

int a[maxSize] = { 0 };
long d[maxSize][2] = { 0 };

int main()
{
    int n = 0;
    cin >> n;
    
    for ( int i = 1; i <= n; ++i ) {
        cin >> a[i];
    }
    
    d[1][0] = a[1];
    
    for ( int i = 2; i <= n; ++i ) {
        d[i][0] = max(d[i - 2][0], d[i - 2][1]) + a[i];
        d[i][1] = d[i - 1][0] + a[i];
    }
    
    cout << max(d[n][0], d[n][1]) << endl;
    
    return 0;
}