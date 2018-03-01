2011번 암호코드
------------

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

constexpr long mod = 1000000;

int main()
{
    string s = "";
    cin >> s;
    
    int n = s.size();
    s = " " + s;
    
    vector<long> d(n + 1, 0);
    
    d[0] = 1;
    
    for ( int i = 1; i <= n; ++i ) {
        int x = s[i] - '0';
        if ( x >= 1 && x <= 9 ) {
            d[i] += d[i - 1];
        }
        if ( i == 1 ) {
            continue;
        }

        x = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if ( x >= 10 && x <= 26 ) {
            d[i] += d[i - 2];
            d[i] %= mod;
        }
    }
    
    cout << d[n] << endl;
    
    return 0;
}
~~~