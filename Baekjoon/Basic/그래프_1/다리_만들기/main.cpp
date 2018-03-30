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