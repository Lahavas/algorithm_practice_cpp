10872번 팩토리얼
-------------

~~~ cpp
#include <iostream>

using namespace std;

int main() 
{
    int n = 0;
    cin >> n;
    
    long long res = 1;
    for ( int i = 1; i <= n; ++i ) {
        res *= i;
    }
    
    cout << res << endl;
    
    return 0;
}
~~~