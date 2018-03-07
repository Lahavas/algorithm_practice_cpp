2609번 최대공약수와 최소공배수
------------------------

~~~ cpp
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    
    int g = gcd(a, b);
    int l = (a * b) / g;
    
    cout << g << endl;
    cout << l << endl;
    
    return 0;
}
~~~