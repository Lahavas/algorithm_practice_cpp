Data Structure 1
================

Baekjoon Online Judge 초급 Ch02. 자료구조 1
----------------------------------------

#### 문제

* [스택](./스택) [[10828번 상세보기](https://www.acmicpc.net/problem/10828)]
* [괄호](./괄호) [[9012번 상세보기](https://www.acmicpc.net/problem/9012)]
* [쇠막대기](./쇠막대기) [[10799번 상세보기](https://www.acmicpc.net/problem/10799)]
* [에디터](./에디터) [[1406번 상세보기](https://www.acmicpc.net/problem/1406)]
* [큐](./큐) [[10845번 상세보기](https://www.acmicpc.net/problem/10845)]
* [조세퍼스 문제](./조세퍼스_문제) [[1158번 상세보기](https://www.acmicpc.net/problem/1158)]
* [덱](./덱) [[10866번 상세보기](https://www.acmicpc.net/problem/10866)]
* [알파벳 개수](./알파벳_개수) [[10808번 상세보기](https://www.acmicpc.net/problem/10808)]
* [알파벳 찾기](./알파벳_찾기) [[10809번 상세보기](https://www.acmicpc.net/problem/10809)]
* [문자열 분석](./문자열_분석) [[10820번 상세보기](https://www.acmicpc.net/problem/10820)]
* [단어 길이 재기](./단어_길이_재기) [[2743번 상세보기](https://www.acmicpc.net/problem/2743)]
* [ROT13](./ROT13) [[11655번 상세보기](https://www.acmicpc.net/problem/11655)]
* [네 수](./네_수) [[10824번 상세보기](https://www.acmicpc.net/problem/10824)]
* [접미사 배열](./접미사_배열) [[11656번 상세보기](https://www.acmicpc.net/problem/11656)]

### 풀이 전 알아야 할 개념

#### 스택

스택은 LIFO 방식으로 데이터를 처리하는 자료구조입니다.  
대표적인 연산은 push, pop, top, empty, size 가 있습니다.  
스택은 array를 이용해 구현할 수 있으며, STL에 구현되어 있는 stack을 사용하는 쪽을 더욱 추천합니다.  
스택에 대한 구체적인 구현 방식은 [스택](./Stack) 을 참고하시면 됩니다.

#### 큐

큐는 FIFO 방식으로 데이터를 처리하는 자료구조입니다.  
대표적인 연산은 push, pop, front, empty, size 가 있습니다.  
큐는 array를 이용해 구현할 수 있으며, STL에 구현되어 있는 queue를 사용하는 쪽을 더욱 추천합니다.  
큐에 대한 구체적인 구현 방식은 [큐](./Queue) 을 참고하시면 됩니다.

#### 덱

덱은 Double-ended queue의 약자입니다.  
대표적인 연산은 push_front, push_back, pop_front, pop_back, front, back 등이 있습니다.  

#### 문자열

아스키코드는 문자의 인코딩 방법입니다.  
'0' = 48, 'A' = 65, 'a' = 97, NULL = 0 을 나타냅니다.  