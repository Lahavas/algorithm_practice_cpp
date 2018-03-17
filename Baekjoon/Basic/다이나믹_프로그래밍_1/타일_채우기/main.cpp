#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<int> d(n + 1, 0);
    
    d[0] = 1;
    
    for ( int i = 2; i <= n; i += 2 ) {
        d[i] = d[i - 2] * 3;
        
        for ( int j = i - 4; j >= 0; j -= 2 ) {
            d[i] += d[j] * 2;
        }
    }
    
    cout << d[n] << '\n';
    
    return 0;
}