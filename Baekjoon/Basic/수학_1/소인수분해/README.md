11653 소인수분해
-------------

N을 소인수분해 했을 때, 나타낼 수 있는 인수 중에서 가장 큰 값은 root(N) 이므로,  
2부터 root(N)까지 반복문을 돌려 N을 나눌 수 없을 때 까지 계속해서 나누는 방법으로 문제를 해결할 수 있습니다.  

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    for ( int i = 2; i * i <= n; ++i ) {
        while ( n % i == 0 ) {
            cout << i << '\n';
            n /= i;
        }
    }
    
    if ( n > 1 ) {
        cout << n << '\n';
    }
    
    return 0;
}
~~~