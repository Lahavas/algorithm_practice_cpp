10951번 A+B - 4
--------------

테스트 케이스를 따로 입력받지 않기 때문에 EOF를 입력 받을 경우 반복을 멈추도록 설계해야합니다.  
scanf의 경우 성공적으로 입력된 argument의 갯수만큼 return 값이 출력됩니다.   

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int a = 0, b = 0;

    while ( cin >> a >> b ) {
        cout << a + b << '\n';
    }

    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

int main() 
{
    int a = 0, b = 0;

    while ( scanf("%d %d", &a, &b) == 2 ) {
        printf("%d\n", a + b);
    }

    return 0;
}
~~~