10430번 나머지
------------

나머지 연산은 (A + B) % C = ((A % C) + (B % C)) % C 가 성립함을 말합니다.  
이를 증명하기 위해서는 다음과 같은 과정이 필요합니다.  

> A = (q1 * C) + r1, B = (q2 * C) + r2  
> A + B = (q1 + q2) * C + (r1 + r2)  
> A % C = r1, B % C = r2  
> (A + B) % C = (r1 + r2) % C  
> (A + B) % C = ((A % C) + (B % C)) % C  

이는 곱셈에서도 동일하게 적용됩니다.  

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    
    cout << (a + b) % c << '\n';
    cout << (a % c + b % c) % c << '\n';
    cout << (a * b) % c << '\n';
    cout << (a % c * b % c) % c << '\n';
    
    return 0;
}
~~~