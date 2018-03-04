#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    long n = 0;
    int b = 0;
    cin >> n >> b;
    
    string res = "";
    
    while ( n > 0 ) {
        int r = n % b;
        
        if ( r < 10 ) {
            res += (char)(r + '0');
        } else {
            res += (char)(r - 10 + 'A');
        }
        
        n /= b;
    }
    
    reverse(res.begin(), res.end());
    cout << res << endl;
    
    return 0;
}