Mathematics 1
==============

Baekjoon Online Judge 초급 Ch04. 수학1
------------------------------------

#### 문제

* [나머지](./나머지) [[10430번 상세보기](https://www.acmicpc.net/problem/10430)]
* [최대공약수와 최소공배수](./최대공약수와_최소공배수) [[2609번 상세보기](https://www.acmicpc.net/problem/2609)]
* [최소공배수](./최소공배수) [[1934번 상세보기](https://www.acmicpc.net/problem/1934)]
* [GCD 합](./GCD_합) [[9613번 상세보기](https://www.acmicpc.net/problem/9613)]
* [진법 변환 2](./진법_변환_2) [[11005번 상세보기](https://www.acmicpc.net/problem/11005)]
* [진법 변환](./진법_변환) [[2745번 상세보기](https://www.acmicpc.net/problem/2745)]
* [2진수 8진수](./2진수_8진수) [[1373번 상세보기](https://www.acmicpc.net/problem/1373)]
* [8진수 2진수](./8진수_2진수) [[1212번 상세보기](https://www.acmicpc.net/problem/1212)]
* [-2진수](./-2진수) [[2089번 상세보기](https://www.acmicpc.net/problem/2089)]
* [Base Conversion](./Base_Conversion) [[11576번 상세보기](https://www.acmicpc.net/problem/11576)]
* [소수 찾기](./소수_찾기) [[1978번 상세보기](https://www.acmicpc.net/problem/1978)]
* [소수 구하기](./소수_구하기) [[1929번 상세보기](https://www.acmicpc.net/problem/1929)]
* [골드바흐의 추측](./골드바흐의_추측) [[6588번 상세보기](https://www.acmicpc.net/problem/6588)]
* [소인수분해](./소인수분해) [[11653번 상세보기](https://www.acmicpc.net/problem/11653)]
* [팩토리얼](./팩토리얼) [[10872번 상세보기](https://www.acmicpc.net/problem/10872)]
* [팩토리얼 0의 개수](./팩토리얼_0의_개수) [[1676번 상세보기](https://www.acmicpc.net/problem/1676)]
* [조합 0의 개수](./조합_0의_개수) [[2004번 상세보기](https://www.acmicpc.net/problem/2004)]

### 풀이 전 알아야 할 개념

#### 나머지 연산 (Modular Arithmetic)

나머지 연산은 (A + B) % C = ((A % C) + (B % C)) % C 가 성립함을 말합니다.  
보통 DP에서 너무 큰 값이 주어졌을 경우 해당 연산을 통해 처리할 수 있습니다.

증명은 다음과 같습니다.  
> A = q1 * C + r1 이고 B = q2 * C + r2 일 때,  
> A + B = (q1 + q1) * C + (r1 + r2) 라고 할 수 있습니다.
> 이 때, A % C = r1 이고 B % C = r2 이며, (A + B) % C = (r1 + r2) % C 이므로  
> ((A % C) + (B % C)) % C = (A + B) % C 임을 알 수 있습니다.
  
이는 곱셈의 경우에도 (A * B) % C = ((A % C) * (B * C)) % C 가 성립하지만,  
나눗셈의 경우에는 성립하지 않습니다.  

뺄셈의 경우에는 나머지 연산을 한 결과가 음수가 나올 수 있기 때문에,  
(A - B) % C = (((A % C) - (B % C)) + C) % C 와 같이 연산할 경우에 완전히 성립합니다.

나머지 연산에 대한 문제는 [나머지](./나머지) 에서 확인할 수 있습니다.

#### 최대공약수 (Greatest Common Divisor) && 최소공배수 (Least Common Multiple)

두 수 A와 B의 최대공약수 G는 A와 B의 공통된 약수 중에서 가장 큰 정수입니다.  
*최대공약수가 1인 두 수를 서로소(Coprime)라고 합니다.*  

최대공약수를 구하는 첫번째 방법은 2부터 min(A, B)까지 모든 정수로 나누어 보는 방법입니다.  
이를 코드로 표현하면 다음과 같습니다.  

~~~ cpp
int g = 1;
for ( int i = 2; i <= min(a, b); ++i ) {
    if ( a % i == 0 && b % i == 0 ) {
        g = i;
    }
}
~~~

최대공약수를 구하는 두번째 방법은 **유클리드 호제법(Euclidean Algorithm)** 을 이용하는 방법입니다.  
A를 B로 나눈 나머지를 R이라고 했을 때, GCD(A, B) = GCD(B, R) 이 성립합니다.  
이 때, R이 0일 때 B는 최대공약수입니다.  
이를 재귀함수를 사용하여 구현하면 다음과 같습니다.   

~~~ cpp
int gcd(int a, int b) 
{
    if ( b == 0 ) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
~~~

이를 재귀함수를 사용하지 않고 구현하면 다음과 같습니다.  

~~~ cpp
int gcd(int a, int b)
{
    while ( b != 0 ) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}
~~~

최소공배수는 두 수의 공통된 배수 중에서 가장 작은 정수입니다.  
최소공배수 L = G * (A / G) * (B / G) 이므로, L = (A * B) / G 라고 할 수 있습니다.

#### 진법 변환 (Base Conversion)

1. 10진법 수 N을 B진법으로 바꾸려면 N이 0이 될 때까지 N을 B로 나눈 나머지를 계속 구하면 됩니다.
2. B진법 수 N을 10진법 수로 바꾸려면 B^k를 곱하면서 더해가면 됩니다.
3. A진법 수 N을 B진법 수로 바꾸려면 A진법 -> 10진법 -> B진법 순서대로 변환해가면 됩니다.

#### 소수 (Prime Number)

소수는 *약수가 1과 자기 자신 밖에 없는 수* 입니다.  
N보다 작은 소수를 구할 때, 소수가 존재할 수 있는 범위는 2부터 root(N) 입니다.  
그러므로 소수임을 판별하는 코드는 다음과 같이 쓸 수 있습니다.

~~~ cpp
bool prime(int n)
{
    if ( n < 2 ) {
        return false;
    }
    for ( int i = 2; i * i <= n; ++i ) {
        if ( n % i == 0 ) {
            return false;
        }
    }
    return true;
}
~~~