2004번 조합 0의 개수
----------------

nCm의 끝자리 0의 갯수를 구하는 문제입니다.  
10 = 2 * 5 이므로, nCm의 소인수분해 중 2의 배수의 갯수와 5의 배수의 갯수 중 작은 값을 구하여 문제를 해결할 수 있습니다.  

~~~ cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    long two = 0, five = 0;
    long n = 0, m = 0;
    cin >> n >> m;
    
    for ( long i = 2; i <= n; i *= 2 ) {
        two += (n / i);
    }
    for ( long i = 2; i <= (n - m); i *= 2 ) {
        two -= ((n - m) / i);
    }
    for ( long i = 2; i <= m; i *= 2 ) {
        two -= (m / i);
    }
    
    for ( long i = 5; i <= n; i *= 5 ) {
        five += (n / i);
    }
    for ( long i = 5; i <= (n - m); i *= 5 ) {
        five -= ((n - m) / i);
    }
    for ( long i = 5; i <= m; i *= 5 ) {
        five -= (m / i);
    }
    
    cout << min(two, five) << endl;
    
    return 0;
}
~~~