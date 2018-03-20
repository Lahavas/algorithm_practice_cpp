11005번 진법 변환 2
----------------

10진법 수인 N을 B진법 수로 바꿔 출력하는 문제입니다.  
N이 0이 될 때까지 N을 B로 나누고, 구해진 N % B 의 배열을 역순으로 출력하면 됩니다.  

~~~ cpp
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    long n = 0;
    int b = 0;
    cin >> n >> b;
    
    string res;
    
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
    cout << res << '\n';
    
    return 0;
}
~~~