Algorithm and Input/Output
==========================

Baekjoon Online Judge 초급 Ch01. 알고리즘과 입출력
---------------------------------------------

### 문제

* [Hello World](./Hello_World) [[2557번 상세보기](https://www.acmicpc.net/problem/2557)]
* [A+B](./A+B) [[1000번 상세보기](https://www.acmicpc.net/problem/1000)]
* [A+B - 2](./A+B_2) [[2558번 상세보기](https://www.acmicpc.net/problem/2558)]
* [A+B - 3](./A+B_3) [[10950번 상세보기](https://www.acmicpc.net/problem/10950)]
* [A+B - 4](./A+B_4) [[10951번 상세보기](https://www.acmicpc.net/problem/10951)]
* [A+B - 5](./A+B_5) [[10952번 상세보기](https://www.acmicpc.net/problem/10952)]
* [A+B - 6](./A+B_6) [[10953번 상세보기](https://www.acmicpc.net/problem/10953)]
* [A+B - 7](./A+B_7) [[11021번 상세보기](https://www.acmicpc.net/problem/11021)]
* [A+B - 8](./A+B_8) [[11022번 상세보기](https://www.acmicpc.net/problem/11022)]
* [그대로 출력하기](./Output_as_it_is) [[11718번 상세보기](https://www.acmicpc.net/problem/11718)]
* [그대로 출력하기 2](./Output_as_it_is_2) [[11719번 상세보기](https://www.acmicpc.net/problem/11719)]
* [숫자의 합](./Number_of_total) [[11720번 상세보기](https://www.acmicpc.net/problem/11720)]
* [열 개씩 끊어 출력하기](./Divide_by_ten_letters) [[11721번 상세보기](https://www.acmicpc.net/problem/11721)]

### 풀이 전 알아야 할 개념

#### C++14의 입/출력

C++14의 입출력 방법은 크게 두 가지가 있습니다.  
첫 번째는 C언어에서 사용한 표준 입출력 함수들을 사용하는 방법입니다.  
이 경우에 cstdio라는 header 파일을 포함시켜주면 printf, scanf등의 함수를 사용할 수 있습니다.

~~~ cpp
#include <cstdio>

int main() {
    printf("Hello, World!");
    return 0;
}
~~~

두 번째는 cin, cout과 같은 c++에서 제공하는 입출력 함수들을 사용하는 방법입니다.  
iostream이라는 header 파일을 포함시켜주면 사용할 수 있다.  
std namespace를 생략하기 위해 `using namespace std` 를 사용하면 더욱 좋습니다.  
성능이 cstdio에 비해 떨어지며, 이를 보완하기 위해 `ios_base::sync_with_stdio(false)`와 함께 사용하기도 합니다.  

~~~ cpp
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout << "Hello, World!" << endl;
    return 0;
}
~~~

문자열 한 줄을 입력받는 경우는 총 두가지가 있습니다.

1. 공백 단위로 한 줄을 입력 받는 경우

단어 기준으로 한 줄을 입력 받는 경우에는 string을 헤더로 설정해준 뒤에,  
`scanf("%s", string);`  
`cin >> string;`  
를 사용해주면 됩니다.

2. 한 줄을 그대로 입력 받는 경우

    1. `fgets(string, 100, stdin);`

        fgets는 \n까지 전부 입력받기 때문에, 출력시에도 그대로 적용될 수 있으니 주의해야합니다.  

    2. `scanf("%[^\n]\n", string);`

        format string에서의 %[]는 대괄호 내부의 문자만 입력받겠다는 표현입니다.  
        그리고 대괄호 안의 ^는 뒤의 문자를 제외하겠다는 표현입니다.
    
    3. `getline(cin, string);`

        getline은 string header 내의 함수로, stream을 parameter로 입력받습니다.
