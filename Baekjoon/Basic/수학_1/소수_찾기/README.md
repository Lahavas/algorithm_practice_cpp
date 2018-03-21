1978번 소수 찾기
-------------

정수 N이 소수인지 아닌지 판별하는 방법은, 2부터 root(N) 까지의 자연수로 나누어 떨어지는지를 통해 확인 가능합니다.  

~~~ cpp
#include <iostream>

using namespace std;

bool prime(int n) 
{
    if ( n < 2 ) {
        return false;
    }
    
    for ( int i = 2; i * i <= n; ++i ) {
        if ( n % i == 0 ) {
            return false;
        }
    }
    
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;
    
    int res = 0;

    while ( cnt-- ) {
        int n = 0;
        cin >> n;
        if ( prime(n) == true ) {
            ++res;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
~~~