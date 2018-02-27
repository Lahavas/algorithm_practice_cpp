Dynamic Programming 1
=====================

Baekjoon Online Judge 초급 Ch03. 다이나믹 프로그래밍 1
------------------------------------------------

#### 문제

* [1로 만들기](./Make_It_One) [[1463번 상세보기](https://www.acmicpc.net/problem/1463)]
* [2xn 타일링](./Two_times_N_1) [[11726번 상세보기](https://www.acmicpc.net/problem/11726)]
* [2xn 타일링 2](./Two_times_N_2) [[11727번 상세보기](https://www.acmicpc.net/problem/11727)]
* [1,2,3 더하기](./Add_One_Two_Three) [[9095번 상세보기](https://www.acmicpc.net/problem/9095)]
* [붕어빵 판매하기](./Selling_Bread) [[11052번 상세보기](https://www.acmicpc.net/problem/11052)]
* [쉬운 계단 수](./Easy_Stair_Number) [[10844번 상세보기](https://www.acmicpc.net/problem/10844)]
* [오르막 수](./Ascending_Number) [[11057번 상세보기](https://www.acmicpc.net/problem/11057)]
* [이친수](./Pinary_Number) [[2193번 상세보기](https://www.acmicpc.net/problem/2193)]
* [스티커](./Sticker) [[9465번 상세보기](https://www.acmicpc.net/problem/9465)]
* 포도주 시식 [[2156번 상세보기](https://www.acmicpc.net/problem/2156)]
* 가장 긴 증가하는 부분 수열 [[11053번 상세보기](https://www.acmicpc.net/problem/11053)]
* 가장 큰 증가 부분 수열 [[11055번 상세보기](https://www.acmicpc.net/problem/11055)]
* 가장 긴 감소하는 부분 수열 [[11722번 상세보기](https://www.acmicpc.net/problem/11722)]
* 가장 긴 바이토닉 부분 수열 [[11054번 상세보기](https://www.acmicpc.net/problem/11054)]
* 연속합 [[1912번 상세보기](https://www.acmicpc.net/problem/1912)]
* 계단 오르기 [[2579번 상세보기](https://www.acmicpc.net/problem/2579)]
* 제곱수의 합 [[1699번 상세보기](https://www.acmicpc.net/problem/1699)]
* 타일 채우기 [[2133번 상세보기](https://www.acmicpc.net/problem/2133)]
* 파도반 수열 [[9461번 상세보기](https://www.acmicpc.net/problem/9461)]
* 합분해 [[2225번 상세보기](https://www.acmicpc.net/problem/2225)]
* 암호코드 [[2011번 상세보기](https://www.acmicpc.net/problem/2011)]

### 풀이 전 알아야 할 개념

#### 다이나믹 프로그래밍

다이나믹 프로그래밍은 큰 문제를 작은 문제로 나눠서 푸는 알고리즘입니다.  
다음 두 가지 속성을 만족합니다.  

1. Overlapping Subproblem
    * 큰 문제와 작은 문제는 같은 방식으로 풀 수 있습니다.
    * 큰 문제는 작은 문제로 쪼갤 수 있습니다.
2. Optimal Substructure
    * 큰 문제의 정답을 작은 문제의 정답에서 구할 수 있습니다.

작은 문제를 기록하기 위해 배열을 구현하는 Memorization을 통해 다이나믹 프로그래밍을 구현할 수 있습니다.  

#### Top-down VS Bottom-up

* Top-down

    Top-down은 재귀 함수를 이용하여 다이나믹 프로그래밍을 푸는 방식입니다.  
    시간복잡도는 (재귀함수 하나의 시간 복잡도) X (반복 횟수) 를 통해 구할 수 있습니다.  

    1. 큰 문제를 작은 문제로 나눕니다
    2. 작은 문제를 풉니다
    3. 큰 문제를 풉니다

~~~ cpp
int dp[100];
int fibonacci(int n) {
    if ( n <= 1 ) {
        return n;
    } else {
        if ( dp[n] > 0 ) {
            return dp[n];
        }
        dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return dp[n];
    }
}
~~~

* Bottom-up

    Bottom-up은 반복문를 이용하여 다이나믹 프로그래밍을 푸는 방식입니다.  
    작은 문제부터 원하는 값을 구할 때까지 차례대로 풀이합니다.  

~~~ cpp
int dp[100];
int fibonacci(int n) {
    dp[0] = 0;
    dp[1] = 1;

    for ( int i = 2; i <= n; i++ ) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
~~~