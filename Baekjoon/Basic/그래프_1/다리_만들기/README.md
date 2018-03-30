2146번 다리 만들기
---------------

두 섬을 연결하는 가장 짧은 다리를 찾는 문제입니다.  
우선 섬을 그룹으로 나누고, 각각의 그룹에 대해 다른 섬까지 거리를 계산하여 문제를 해결할 수 있습니다.  
BFS를 사용하여 최단 거리를 계산하여 문제를 해결할 수 있습니다.  

1. BFS를 사용하여 섬과 섬 간의 최단 거리 계산

~~~ cpp
#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 100;
constexpr int DIR_NUM = 4;

int a[MAX][MAX] = { 0 };
int g[MAX][MAX] = { 0 };
int d[MAX][MAX] = { 0 };

int dx[DIR_NUM] = { 0, 0, 1, -1 };
int dy[DIR_NUM] = { 1, -1, 0, 0 };

int main() 
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            if ( a[i][j] == 1 && g[i][j] == 0 ) {
                cnt += 1;

                queue<pair<int, int>> q;

                q.push(make_pair(i, j));    
                g[i][j] = cnt;

                while ( !q.empty() ) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for ( int t = 0; t < 4; ++t ) {
                        int nx = x + dx[t];
                        int ny = y + dy[t];

                        if ( nx >= 0 && nx < n && ny >= 0 && ny < n ) {
                            if ( a[nx][ny] == 1 && g[nx][ny] == 0 ) {
                                q.push(make_pair(nx, ny));
                                g[nx][ny] = cnt;
                            }
                        }
                    }
                }
            }
        }
    }

    int res = -1;
    for ( int l = 1; l <= cnt; ++l ) {
        queue<pair<int, int>> q;

        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                d[i][j] = -1;
                
                if ( g[i][j] == l ) {
                    q.push(make_pair(i, j));
                    d[i][j] = 0;
                }
            }
        }

        while ( !q.empty() ) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for ( int t = 0; t < 4; ++t ) {
                int nx = x + dx[t];
                int ny = y + dy[t];

                if ( nx >= 0 && nx < n && ny >= 0 && ny < n ) {
                    if ( d[nx][ny] == -1 ) {
                        d[nx][ny] = d[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }

        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                if ( a[i][j] == 1 && g[i][j] != l ) {
                    if ( res == -1 || d[i][j] - 1 < res ) {
                        res = d[i][j] - 1;
                    }
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}
~~~

2. 섬의 그룹과 거리를 확장하여, 인접한 칸의 그룹 번호가 다를 때의 거리를 통해 최단 거리 구하기

~~~ cpp
#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 100;
constexpr int DIR_NUM = 4;

int a[MAX][MAX] = { 0 };
int g[MAX][MAX] = { 0 };
int d[MAX][MAX] = { 0 };

int dx[DIR_NUM] = { 0, 0, 1, -1 };
int dy[DIR_NUM] = { 1, -1, 0, 0 };

int main() 
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            if ( a[i][j] == 1 && g[i][j] == 0 ) {
                cnt += 1;

                queue<pair<int, int>> q;

                q.push(make_pair(i, j));
                g[i][j] = cnt;

                while ( !q.empty() ) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for ( int t = 0; t < 4; ++t ) {
                        int nx = x + dx[t];
                        int ny = y + dy[t];
                        
                        if ( nx >= 0 && nx < n && ny >= 0 && ny < n ) {
                            if ( a[nx][ny] == 1 && g[nx][ny] == 0 ) {
                                q.push(make_pair(nx, ny));
                                g[nx][ny] = cnt;
                            }
                        }
                    }
                }
            }
        }
    }

    queue<pair<int, int>> q;

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            d[i][j] = -1;
            
            if ( a[i][j] == 1 ) {
                q.push(make_pair(i, j));
                d[i][j] = 0;
            }
        }
    }

    while ( !q.empty() ) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for ( int t = 0; t < 4; ++t ) {
            int nx = x + dx[t];
            int ny = y + dy[t];
            if ( nx >= 0 && nx < n && ny >= 0 && ny < n ) {
                if ( d[nx][ny] == -1 ) {
                    q.push(make_pair(nx, ny));
                    d[nx][ny] = d[x][y] + 1;
                    g[nx][ny] = g[x][y];
                }
            }
        }
    }

    int res = -1;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            for ( int t = 0; t < 4; ++t ) {
                int x = i + dx[t];
                int y = j + dy[t];
                if ( x >= 0 && x < n && y >= 0 && y < n ) {
                    if ( g[i][j] != g[x][y] ) {
                        if ( res == -1 || res > d[i][j] + d[x][y] ) {
                            res = d[i][j] + d[x][y];
                        }
                    }
                }
            }
        }
    }

    cout << res << '\n';
    
    return 0;
}
~~~