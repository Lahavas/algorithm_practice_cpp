2089번 -2진수
-----------

-2진수를 10진수로 바꿔 출력하는 문제입니다.  
N진수를 10진수로 바꿔 출력하는 문제와 동일한 방식으로 풀 수 있지만, 음수를 2로 나눌 때 나머지가 음수가 나오지 않도록 문제를 풀이해야합니다.  

~~~ cpp
#include <iostream>

using namespace std;

void convert(int n) 
{
    if ( n == 0 ) {
        return;
    }
    
    if ( n % 2 == 0 ) {
        convert(-(n / 2));
        cout << "0";
    } else {
        if ( n > 0 ) {
            convert(-(n / 2));
        } else {
            convert((-n + 1) / 2);
        }
        
        cout << "1";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    if ( n == 0 ) {
        cout << "0" << '\n';
    } else {
        convert(n);
        cout << '\n';
    }
    
    return 0;
}
~~~