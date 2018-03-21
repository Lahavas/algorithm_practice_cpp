1676번 팩토리얼 0의 개수
-------------------

팩토리얼 0의 개수는 N!의 소인수분해를 통해 알 수 있습니다.  
이 때, 10 = 2 * 5 이며, 팩토리얼의 특성상 2의 배수가 5의 배수보다 무조건 많기 때문에 N!에서의 5가 몇 번 들어가는지 찾아야 합니다.  
이를 찾기 위해 N / 5^1 + N / 5^2 + ... + N / 5^K 를 통해 갯수를 구할 수 있습니다.  

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    int res = 0;
    for ( int i = 5; i <= n; i *= 5 ) {
        res += n / i;
    }
    cout << res << '\n';
    
    return 0;
}
~~~