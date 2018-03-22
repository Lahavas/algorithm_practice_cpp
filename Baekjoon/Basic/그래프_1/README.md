Graph 1
=======

Baekjoon Online Judge 초급 Ch06. 그래프 1
--------------------------------------

#### 문제

* DFS와 BFS [[1260번 상세보기](https://www.acmicpc.net/problem/1260)]
* 연결 요소의 개수 [[11724번 상세보기](https://www.acmicpc.net/problem/11724)]
* 이분 그래프 [[1707번 상세보기](https://www.acmicpc.net/problem/1707)]
* 순열 사이클 [[10451번 상세보기](https://www.acmicpc.net/problem/10451)]
* 반복수열 [[2331번 상세보기](https://www.acmicpc.net/problem/2331)]
* 텀 프로젝트 [[9466번 상세보기](https://www.acmicpc.net/problem/9466)]
* 단지번호붙이기 [[2667번 상세보기](https://www.acmicpc.net/problem/2667)]
* 섬의 개수 [[4963번 상세보기](https://www.acmicpc.net/problem/4963)]
* 미로 탐색 [[2178번 상세보기](https://www.acmicpc.net/problem/2178)]
* 토마토 [[7576번 상세보기](https://www.acmicpc.net/problem/7576)]
* 다리 만들기 [[2146번 상세보기](https://www.acmicpc.net/problem/2146)]

### 풀이 전 알아야 할 개념

#### 그래프와 관련된 용어

* 그래프 (Graph)
    * **정점**과 **간선**으로 구성된 자료구조의 일종입니다.
    * **G = (V, E)** 로 표현합니다.
    * 간선의 방향에 따라 다음과 같이 구분합니다.
        * 방향 있는 그래프 (Directed Graph)
        * 방향 없는 그래프 (Undirected Graph)
            * 양방향 그래프 (Bidirection Graph) 라고도 합니다.
* 정점 (Node, Vertex)
    * 경로 (Path)
        * 정점 A에서 정점 B로 가는 경로입니다.
        * 같은 정점을 두 번 이상 방문하지 않는 경로를 *단순 경로 (Simple Path)* 라고 합니다.
    * 사이클 (Cycle)
        * 경로 중 시작점과 끝점이 같은 케이스입니다.
        * 정점 A에서 다시 정점 A로 돌아오는 경로입니다.
* 간선 (Edge)
    * 정점과 정점 간의 관계를 나타냅니다.
    * 여러개의 간선 (Multiple Edge)
        * 두 정점 사이에 간선이 여러 개일 수 있습니다.
    * 루프 (Loop)
        * 간선의 양 끝 점이 같은 경우를 루프라고 합니다.
* 가중치 (Weight)
    * 정점 A에서 정점 B로 갈 때 필요한 비용을 가중치라고 하며, **간선**에 가중치를 부여합니다.
    * 그래프 전체에 가중치가 존재하지 않을 경우, 모든 가중치를 1로 지정합니다.
* 차수 (Degree)
    * 정점에 연결되어 있는 간선의 갯수입니다.
    * 간선에 방향이 존재할 경우에, 차수의 종류는 다음과 같습니다.
        * 정점에 들어가는 간선의 갯수 (in-degree)
        * 정점을 나가는 간선의 갯수 (out-degree)