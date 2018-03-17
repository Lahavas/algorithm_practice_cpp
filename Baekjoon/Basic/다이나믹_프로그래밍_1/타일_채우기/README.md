2133번 타일 채우기
---------------

D[N]은 3XN을 채울 수 있는 방법의 수로 정의할 수 있습니다.  
길이가 2일 때, 길이가 4일 때의 경우의 수가 존재하기 때문에,  
D[N] = 3 * D[N-2] + 2 * D[N-4] + 2 * D[N-6] + ... + 2 * D[0] 이라고 할 수 있습니다.

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<int> d(n + 1, 0);
    
    d[0] = 1;
    
    for ( int i = 2; i <= n; i += 2 ) {
        d[i] = d[i - 2] * 3;
        
        for ( int j = i - 4; j >= 0; j -= 2 ) {
            d[i] += d[j] * 2;
        }
    }
    
    cout << d[n] << '\n';
    
    return 0;
}
~~~