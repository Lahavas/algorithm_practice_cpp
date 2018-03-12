1924번 2007년
------------

날짜를 입력받고, 해당 날짜의 요일을 출력하는 문제입니다.  
필요한 고정값인 각 월마다의 날짜와 요일명을 배열에 저장하고,  
입력된 월 정보를 통해 해당 월까지의 첫째날 이전의 날짜의 갯수를 찾은 뒤 입력된 일 정보를 통해 입력 날짜까지의 전체 일수를 계산합니다.  
이후에 (전체 일수 % 7)을 통해 해당 요일을 구할 수 있습니다.

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

constexpr int M_NUM = 12;
constexpr int D_NUM = 7;

const int a[M_NUM] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const string d[D_NUM] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main()
{
    ios_base::sync_with_stdio(false);

    int x = 0, y = 0;
    cin >> x >> y;

    int n = 0;
    for ( int i = 1; i < x; ++i ) {
        n += a[i - 1];
    }
    n += y;

    cout << d[n % D_NUM] << '\n';

    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

constexpr int M_NUM = 12;
constexpr int D_NUM = 7;

const int a[M_NUM] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const char *d[D_NUM] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main()
{
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);

    int n = 0;
    for ( int i = 1; i < x; ++i ) {
        n += a[i - 1];
    }
    n += y;

    printf("%s\n", d[n % D_NUM]);

    return 0;
}
~~~