#include <iostream>

using namespace std;

constexpr long mod = 1000000000;
constexpr int size = 201;

long long d[size][size] = { 0 };

int main()
{
    int n = 0;
    int k = 0;
    
    cin >> n >> k;
    
    d[0][0] = 1;
    
    for ( int i = 1; i <= k; ++i ) {
        for ( int j = 0; j <= n; ++j ) {
            for ( int l = 0; l <= j; ++l ) {
                d[i][j] += d[i - 1][j - l];
                d[i][j] %= mod;
            }
        }
    }
    
    cout << d[k][n] << endl;
    
    return 0;
}