10872번 팩토리얼
-------------

팩토리얼 N! = 1 * 2 * ... * N 이므로 반복문을 통해 문제를 해결할 수 있습니다.  

~~~ cpp
#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    long long res = 1;
    for ( int i = 1; i <= n; ++i ) {
        res *= i;
    }
    
    cout << res << '\n';
    
    return 0;
}
~~~