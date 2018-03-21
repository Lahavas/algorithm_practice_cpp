1929번 소수 구하기
---------------

M부터 N 사이의 소수를 구하는 문제입니다.  
우선 1부터 N까지의 소수를 구한 뒤 M부터 N까지의 소수를 출력해주면 됩니다.  
에라토스테네스의 체를 사용하여 문제를 빠르게 해결할 수 있습니다.  

~~~ cpp
#include <iostream>

using namespace std;

constexpr int MAX = 1000000;

bool check[MAX + 1] = { false };

int main()
{
    ios_base::sync_with_stdio(false);

    check[0] = true;
    check[1] = true;
    
    for ( int i = 2; i * i <= MAX; ++i ) {
        if ( check[i] == false ) {
            for ( int j = i + i; j <= MAX; j += i ) {
                check[j] = true;
            }
        }
    }
    
    int m = 0, n = 0;
    cin >> m >> n;
    
    for ( int i = m; i <= n; ++i ) {
        if ( check[i] == false ) {
            cout << i << '\n';
        }
    }
    
    return 0;
}
~~~