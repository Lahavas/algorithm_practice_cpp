11720번 숫자의 합
--------------

1. 숫자 하나씩 입력받아 합을 출력하기.

~~~ cpp
#include <cstdio>

int main() {
    int test_case;
    scanf("%d", &test_case);

    int sum = 0;

    while ( test_case-- ) {
        int num;
        scanf("%1d", &num);
        sum += num;
    }

    printf("%d\n", sum);

    return 0;
}
~~~

2. string으로 입력받아 숫자로 변환하여 합을 출력하기.

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    string input;
    cin >> input;

    int sum = 0;

    for ( int i = 0; i < test_case; i++ ) {
        int num = input.at(i) - '0';
        sum += num;
    }

    cout << sum << endl;

    return 0;
}
~~~