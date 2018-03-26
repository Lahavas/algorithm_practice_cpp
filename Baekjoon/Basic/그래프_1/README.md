Graph 1
=======

Baekjoon Online Judge 초급 Ch06. 그래프 1
--------------------------------------

#### 문제

* [DFS와 BFS](./DFS와_BFS) [[1260번 상세보기](https://www.acmicpc.net/problem/1260)]
* [연결 요소의 개수](./연결_요소의_개수) [[11724번 상세보기](https://www.acmicpc.net/problem/11724)]
* [이분 그래프](./이분_그래프) [[1707번 상세보기](https://www.acmicpc.net/problem/1707)]
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

#### 그래프의 표현

그래프를 표현하는 방법은 크게 두 가지 방법이 있습니다.  
 
첫 번째 방법은 **인접 행렬 (Adjacency Matrix)** 을 이용하여 그래프를 표현하는 방법입니다.  
정점의 개수를 V라고 했을 때, V * V 크기의 이차원 배열을 이용합니다.  
정점 i에서 정점 j 까지의 간선이 존재할 때, A[i][j] = w (w는 해당 간선의 가중치) 입니다.  
이 때, 양방향 그래프는 대각선을 기준으로 양쪽이 대칭을 이룹니다.  
인접 행렬은 그래프에는 존재하지 않는 방식까지 저장하기 때문에 O(V^2)만큼의 공간 복잡도가 들며, 비효율적이여서 잘 사용하지 않습니다.  

다음 코드는 양방향 그래프이며, 가중치가 존재하지 않는 경우에 인접 행렬을 사용하여 그래프를 표현한 코드입니다.  

~~~ cpp
#include <cstdio>

int a[10][10] = { 0 };

int main()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    for ( int i = 0; i < m; ++i ) {
        int u = 0, v = 0;
        scanf("%d %d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }
}
~~~

두 번째 방법은 **인접 리스트 (Adjacency List)** 를 이용하여 그래프를 표현하는 방법입니다.  
A[i]에는 i와 연결된 정점을 Linked-List를 통해 표현합니다.  
모든 간선은 한 번씩 저장이 되므로 O(E)만큼의 공간 복잡도가 들어 효율적입니다.  
주로 Linked-List를 직접 구현하기 보단, Vector와 같이 가변적인 배열을 이용하여 구현합니다.  

다음 코드는 양방향 그래프이며, 가중치가 존재하는 경우에 인접 리스트를 사용하여 그래프를 표현한 코드입니다.  

~~~ cpp
#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> a[10];

int main()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    
    for ( int i = 0; i < m; ++i ) {
        int u = 0, v = 0, w = 0;
        scanf("%d %d %d", &u, &v, &w);

        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
    }
}
~~~

세 번째 방법은 **간선 리스트 (Edge List)** 를 이용하여 그래프를 표현하는 방법입니다.  
STL과 같은 라이브러리를 이용하지 못하는 등의 특수한 경우에 주로 사용되는 방법입니다.  
간선의 시작점과 끝점을 Element로 하는 구조체의 일차원 배열을 이용하여 구현하며, 간선을 모두 저장합니다.  
이후 간선의 시작점의 갯수에 대한 배열을 두어 간선에 대한 Indexing을 통해 그래프를 탐색할 수 있습니다.  
배열의 크기가 간선의 크기이기 때문에, O(E)만큼의 공간 복잡도가 들어갑니다.  

다음 코드는 양방향 그래프이며, 가중치가 존재하는 경우에 간선 리스트를 사용하여 그래프를 표현한 코드입니다.  

~~~ cpp
#include <cstdio>

struct Edge {
    int from, to;
    int weight;

    Edge() {
        from = 0;
        to = 0;
        weight = 0;
    }
};

Edge edge[10];
int cnt[10];

int main()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    
    for ( int i = 0; i < m; ++i ) {
        scanf("%d %d %d", &edge[i].from, &edge[i].to, &edge[i].weight);

        edge[i + m].from = edge[i].to;
        edge[i + m].to = edge[i].from;
    }

    m += 2;

    for ( int i = 0; i < m; ++i ) {
        cnt[edge[i].from] += 1;
    }

    for ( int i = 1; i <= n; ++i ) {
        cnt[i] += cnt[i - 1];
    }
}
~~~

#### 그래프의 탐색

그래프를 탐색하는 주 목적은 모든 정점을 최소한 한 번씩 방문하는 것입니다.
그래프를 탐색하는 방법은 크게 두 가지 방법이 있습니다.  

첫 번째 방법은 **깊이 우선 탐색 (Depth First Search)** 입니다.  
최대한 깊게 탐색하는 것을 목적으로 하며, 스택을 통해 구현합니다.  
이미 한 번 이상 방문한 정점은 check[V] 배열을 통해 관리합니다.  
방법은 정점을 방문할 때 스택에 Push하며, 만약 갈 수 있는 정점이 없다면 갈 수 있는 정점을 찾을 때 까지 Pop을 실행합니다.  
이후에 스택이 비게 되면 탐색을 종료합니다.  

다음 코드는 인접 행렬을 이용하여 그래프를 표현하고, 재귀 호출을 통해 DFS를 구현한 코드입니다.  
정점의 갯수만큼 정점이 인접해있는지를 체크하며, 정점의 갯수만큼 그래프를 탐색하기 때문에 O(V^2)만큼의 시간 복잡도가 들어갑니다.  

~~~ cpp
void dfs(int x)
{
    check[x] = true;
    printf("%d ", x);
    for ( int i = 1; i <= n; ++i ) {
        if ( a[x][i] == 1 && check[i] == false ) {
            dfs(i);
        }
    }
}
~~~

다음 코드는 인접 리스트를 이용하여 그래프를 표현하고, 재귀 호출을 통해 DFS를 구현한 코드입니다.  
인접 리스트는 정점이 인접해있는지, 즉 간선이 존재하는지를 체크할 필요가 없습니다.  
인접 리스트의 모든 간선을 체크하고, 정점의 갯수만큼 그래프를 탐색하기 때문에 O(V+E)만큼의 시간 복잡도가 들어갑니다.  

~~~ cpp
void dfs(int x)
{
    check[x] = true;
    printf("%d ", x);
    for ( int i = 0; i < a[x].size(); ++i ) {
        int y = a[x][i];
        if ( check[y] == false ) {
            dfs(y);
        }
    }
}
~~~

두 번째 방법은 **너비 우선 탐색 (Breadth First Search)** 입니다.  
모든 가중치가 1인 경우에 최단 경로를 찾기 위한 방법으로 사용이 됩니다.  
최대한 넓게 탐색하는 것을 목적으로 하며, 큐를 통해 구현합니다.  
이미 한 번 이상 방문한 정점은 check[V] 배열을 통해 관리합니다.  
방법은 정점에 인접해있는 모든 정점들을 큐와 check 배열에 넣고, 정점들을 모두 큐에 넣었으면 큐를 Pop하고 Front에 저장된 정점에 대해 다시 탐색합니다.  
이후 큐가 비게 되면 탐색을 종료합니다.  

다음 코드는 인접 행렬을 이용하여 그래프를 표현하고, BFS를 구현한 코드입니다.  
정점의 갯수만큼 정점이 인접해있는지를 체크하며, 정점의 갯수만큼 그래프를 탐색하기 때문에 O(V^2)만큼의 시간 복잡도가 들어갑니다.  

~~~ cpp
queue<int> q;

check[1] = true;
q.push(1);

while ( !q.empty() ) {
    int x = q.front();
    q.pop();
    printf("%d ", x);

    for ( int i = 1; i <= n; ++i ) {
        if ( a[x][i] == 1 && check[i] == false ) {
            check[i] = true;
            q.push(i);
        }
    }
}
~~~

다음 코드는 인접 리스트를 이용하여 그래프를 표현하고, BFS를 구현한 코드입니다.  
인접 리스트는 정점이 인접해있는지, 즉 간선이 존재하는지를 체크할 필요가 없습니다.  
인접 리스트의 모든 간선을 체크하고, 정점의 갯수만큼 그래프를 탐색하기 때문에 O(V+E)만큼의 시간 복잡도가 들어갑니다.  

~~~ cpp
queue<int> q;

check[1] = true;
q.push(1);

while ( !q.empty() ) {
    int x = q.front();
    q.pop();
    printf("%d ", x);

    for ( int i = 0; i < a[x].size(); ++i ) {
        int y = a[x][i];
        if ( check[y] == false ) {
            check[y] = true;
            q.push(y);
        }
    }
}
~~~

#### 그래프의 연결 요소 (Connected Component)

그래프에서 직접적으로 연결되어있는 정점의 집합을 그래프의 연결 요소 (Connected Component) 라고 합니다.  
DFS와 BFS를 통해 인접해있는 정점끼리 체크를 하여 연결 요소를 구할 수 있습니다.  

#### 이분 그래프 (Bipartite Graph)

그래프를 A와 B로 나눌 수 있으면 이분 그래프 (Bipartite Graph) 라고 합니다.  
나누어 지는 조건은 다음과 같습니다.  

* A에 포함되어 있는 정점끼리 연결된 간선이 없음
* B에 포함되어 있는 정점끼리 연결된 간선이 없음
* 모든 간선의 한 끝 점은 A에, 다른 끝 점은 B에 존재

DFS와 BFS를 통해 이분 그래프의 여부를 알 수 있습니다.  