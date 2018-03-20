11576번 Base Conversion
-----------------------

A진법의 수를 B진법의 수로 바꿔 출력하는 문제입니다.  
A진수 -> 10진수 -> B진수로 바꿔 출력해서 풀이할 수 있습니다.

~~~ cpp
#include <iostream>

using namespace std;

void convert(int num, int base)
{
    if ( num == 0 ) {
        return;
    }
    
    convert(num / base, base);
    cout << num % base << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a = 0, b = 0;
    cin >> a >> b;
    
    int m = 0;
    cin >> m;
    
    int res = 0;
    for ( int i = 0; i < m; ++i ) {
        int x;
        cin >> x;
        res = res * a + x;
    }
    convert(res, b);
    
    return 0;
}
~~~