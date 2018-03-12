Algorithm and Input/Output
==========================

Baekjoon Online Judge 초급 Ch01. 알고리즘과 입출력
---------------------------------------------

### 문제

* [Hello World](./Hello_World) [[2557번 상세보기](https://www.acmicpc.net/problem/2557)]
* [A+B](./A+B) [[1000번 상세보기](https://www.acmicpc.net/problem/1000)]
* [A+B - 2](./A+B-2) [[2558번 상세보기](https://www.acmicpc.net/problem/2558)]
* [A+B - 3](./A+B-3) [[10950번 상세보기](https://www.acmicpc.net/problem/10950)]
* [A+B - 4](./A+B-4) [[10951번 상세보기](https://www.acmicpc.net/problem/10951)]
* [A+B - 5](./A+B-5) [[10952번 상세보기](https://www.acmicpc.net/problem/10952)]
* [A+B - 6](./A+B-6) [[10953번 상세보기](https://www.acmicpc.net/problem/10953)]
* [A+B - 7](./A+B-7) [[11021번 상세보기](https://www.acmicpc.net/problem/11021)]
* [A+B - 8](./A+B-8) [[11022번 상세보기](https://www.acmicpc.net/problem/11022)]
* [그대로 출력하기](./그대로_출력하기) [[11718번 상세보기](https://www.acmicpc.net/problem/11718)]
* [그대로 출력하기 2](./그대로_출력하기_2) [[11719번 상세보기](https://www.acmicpc.net/problem/11719)]
* [숫자의 합](./숫자의_합) [[11720번 상세보기](https://www.acmicpc.net/problem/11720)]
* [열 개씩 끊어 출력하기](./열_개씩_끊어_출력하기) [[11721번 상세보기](https://www.acmicpc.net/problem/11721)]

### 추가 문제

* [N찍기](./N찍기) [[2741번 상세보기](https://www.acmicpc.net/problem/2741)]
* [기찍 N](./기찍_N) [[2742번 상세보기](https://www.acmicpc.net/problem/2742)]
* [구구단](./구구단) [[2739번 상세보기](https://www.acmicpc.net/problem/2739)]
* [2007년](./2007년) [[1924번 상세보기](https://www.acmicpc.net/problem/1924)]
* [합](./합) [[8393번 상세보기](https://www.acmicpc.net/problem/8393)]
* [최소, 최대](./최소_최대) [[10818번 상세보기](https://www.acmicpc.net/problem/10818)]
* 별찍기 - 1 [[2438번 상세보기](https://www.acmicpc.net/problem/2438)]
* 별찍기 - 2 [[2439번 상세보기](https://www.acmicpc.net/problem/2439)]
* 별찍기 - 3 [[2440번 상세보기](https://www.acmicpc.net/problem/2440)]
* 별찍기 - 4 [[2441번 상세보기](https://www.acmicpc.net/problem/2441)]
* 별찍기 - 5 [[2442번 상세보기](https://www.acmicpc.net/problem/2442)]
* 별찍기 - 7 [[2444번 상세보기](https://www.acmicpc.net/problem/2444)]
* 별찍기 - 8 [[2445번 상세보기](https://www.acmicpc.net/problem/2445)]
* 별찍기 - 9 [[2446번 상세보기](https://www.acmicpc.net/problem/2446)]
* 별찍기 - 12 [[2522번 상세보기](https://www.acmicpc.net/problem/2522)]
* 별찍기 - 16 [[10991번 상세보기](https://www.acmicpc.net/problem/10991)]
* 별찍기 - 17 [[10992번 상세보기](https://www.acmicpc.net/problem/10992)]

### 풀이 전 알아야 할 개념

#### 시간 복잡도

Big O Notation을 사용하여 시간이 얼마나 걸릴지 예상할 수 있습니다.  
대략적으로 O(1) < O(logN) < O(N) < O(NlogN) < O(N^2) < O(N^3) < O(2^N) < O(N!) 입니다.  
백준 온라인 저지의 문제를 풀 경우, 최대의 입력값을 대입할 경우 1억이 나올 경우 대략 1초가 걸립니다.  
O(2^N)은 보통 크기가 N인 집합의 부분 집합을 나타낼 때 확인할 수 있으며,  
O(N!은 보통 크기가 N인 순열을 나타낼 때 확인할 수 있습니다.

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

scanf를 사용할 때 주의할 점은, 문자열이 아닌 문자 혹은 숫자를 입력받을 시에 입력 버퍼에 '\n'이 입력된다는 점입니다.  
위와 같은 경우에는 `getchar();` , `scanf("%*c", c);` 와 같이 강제로 '\n'를 입력받고 지워버리는 방법 혹은,  
입력을 문자열로 받아 따로 처리하는 방법 등을 상황에 맞게 사용하여야 합니다.

두 번째는 cin, cout과 같은 c++에서 제공하는 입출력 함수들을 사용하는 방법입니다.  
iostream이라는 header 파일을 포함시켜주면 사용할 수 있다.  
std namespace를 생략하기 위해 `using namespace std` 를 사용하면 더욱 좋습니다.  
성능이 cstdio에 비해 떨어지며, 이를 보완하기 위해 `ios_base::sync_with_stdio(false)` 와 함께 사용하기도 합니다.  

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
        scanf는 앞의 whitespace을 무시하며, 
    
    3. `getline(cin, string);`

        getline은 string header 내의 함수로, stream을 parameter로 입력받습니다.
