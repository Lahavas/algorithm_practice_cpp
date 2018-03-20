2745번 진법 변환
-------------

B진법 수 N을 10진법으로 바꿔 출력하는 문제입니다.  
자리수를 k라고 하면, 각 자리수의 수에 B^k를 곱하여 전체 합을 구하여 결과를 구할 수 있습니다.  

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string n;
    int b = 0;
    
    cin >> n >> b;
    
    long res = 0;
    
    for ( int i = 0; i < n.size(); ++i ) {
        if ( n[i] >= '0' && n[i] <= '9' ) {
            res = res * b + (n[i] - '0');
        } else {
            res = res * b + (n[i] - 'A' + 10);
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
~~~