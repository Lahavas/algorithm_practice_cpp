2609번 최대공약수와 최소공배수
------------------------

최대공약수를 구하는 가장 효과적인 방법은 유클리드 호제법(Euclidean Algorithm) 을 이용하는 방법입니다.  
A를 B로 나눈 나머지를 R이라고 했을 때, GCD(A, B) = GCD(B, R) 이 성립합니다.  
이 때, R이 0일 때 B는 최대공약수입니다.  

두 수 A와 B의 최소공배수 L은 (A / G) * (B / G) * G 를 통해 구할 수 있습니다.  
즉, L = (A * B) / G 입니다.

1. 재귀함수를 사용하여 최대공약수를 구하기

~~~ cpp
#include <iostream>

using namespace std;

int gcd(int a, int b) 
{
    if ( b == 0 ) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a = 0, b = 0;
    cin >> a >> b;
    
    int g = gcd(a, b);
    int l = (a * b) / g;
    
    cout << g << '\n';
    cout << l << '\n';
    
    return 0;
}
~~~

2. 재귀함수를 사용하지 않고 최대공약수를 구하기

~~~ cpp
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while ( b != 0 ) {
        int r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a = 0, b = 0;
    cin >> a >> b;

    int g = gcd(a, b);
    int l = (a * b) / g;

    cout << g << '\n';
    cout << l << '\n';

    return 0;
}
~~~