Sorting
=======

Baekjoon Online Judge 초급 Ch05. 정렬
-----------------------------------

#### 문제

* [수 정렬하기 2](./수_정렬하기_2) [[2751번 상세보기](https://www.acmicpc.net/problem/2751)]
* [좌표 정렬하기](./좌표_정렬하기) [[11650번 상세보기](https://www.acmicpc.net/problem/11650)]
* [좌표 정렬하기 2](./좌표_정렬하기_2) [[11651번 상세보기](https://www.acmicpc.net/problem/11651)]
* [나이순 정렬](./나이순_정렬) [[10814번 상세보기](https://www.acmicpc.net/problem/10814)]
* [국영수](./국영수) [[10825번 상세보기](https://www.acmicpc.net/problem/10825)]
* [수 정렬하기 3](./수_정렬하기_3) [[10989번 상세보기](https://www.acmicpc.net/problem/10989)]
* [카드](./카드) [[11652번 상세보기](https://www.acmicpc.net/problem/11652)]
* [K번째 수](./K번째_수) [[11004번 상세보기](https://www.acmicpc.net/problem/11004)]
* [버블 소트](./버블_소트) [[1377번 상세보기](https://www.acmicpc.net/problem/1377)]

### 풀이 전 알아야 할 개념

#### 정렬 (Sort)

정렬은 O(N^2)이 걸리는 정렬과, O(NlogN)이 걸리는 정렬이 있습니다.  
전자는 선택 정렬 (Selection Sort), 버블 정렬 (Bubble Sort), 삽입 정렬 (Insertion Sort) 등이 있으며  
후자는 퀵 정렬 (Quick Sort), 힙 정렬 (Heap Sort), 병합 정렬 (Merge Sort) 등이 있습니다.  
정렬은 속도가 빠른 O(NlogN) 시간 복잡도를 가진 정렬을 사용하는 것을 추천합니다.  
C++에서는 STL에서 제공하는 sort Function (algorithm header에 정의) 를 사용하는 것을 권장합니다.  

1. C-Style Array에서 sort 적용

~~~ cpp
int a[n] = { 0 };
sort(a, a + n);
~~~

2. vector에서 sort 적용

~~~ cpp
vector<int> a;
sort(a.begin(), a.end());
~~~

#### 안정 정렬 (Stable Sorting)

안정 정렬 알고리즘은 Element가 같은 것이 있는 경우에 정렬하기 전의 순서가 유지되는 정렬 알고리즘입니다.  
O(N^2)인 정렬 알고리즘 중에는 버블 정렬 (Bubble Sort) 가 이에 해당하며,  
O(NlogN)인 정렬 알고리즘 중에는 병합 정렬 (Merge Sort) 가 이에 해당합니다.  
C++에서는 STL에서 제공하는 stable_sort Function (algorithm header에 정의) 를 사용하는 것을 권장합니다.  