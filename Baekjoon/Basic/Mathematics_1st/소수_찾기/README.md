1978번 소수 찾기
-------------

~~~ cpp
#include <iostream>

using namespace std;

bool prime(int n) {
    if ( n < 2 ) {
        return false;
    }
    
    for ( int i = 2; i <= n - 1; ++i ) {
        if ( n % i == 0 ) {
            return false;
        }
    }
    
    return true;
}

int main() 
{
    int n = 0;
    cin >> n;
    
    int res = 0;
    
    for ( int i = 0; i < n; ++i ) {
        int num = 0;
        cin >> num;
        if ( prime(num) == true ) {
            ++res;
        }
    }
    
    cout << res << endl;
    
    return 0;
}
~~~