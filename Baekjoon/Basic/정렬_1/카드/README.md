11652번 카드
-----------

가지고 있는 카드 중에 가장 많이 가지고 있는 정수를 구하는 문제로,  
정렬을 진행한 뒤에 인접한 수를 비교하여 최대 갯수를 구하여 문제를 풀이할 수 있습니다.  
이 때, 같은 수가 인접해있기 때문에 정렬 뒤에 비교 과정을 풀이하기 위한 시간 복잡도는 O(N)입니다.  

또 다른 방법으로는 정렬을 사용하지 않고 Key-Value Pair 구조인 map을 사용하여 문제를 해결할 수 있습니다.  

1. 정렬을 사용하여 문제를 풀이

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<long long> a(n, 0);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long res = a[0];
    int max_cnt = 1;
    int cnt = 1;
    
    for ( int i = 1; i < n; ++i ) {
        if ( a[i] == a[i - 1] ) {
            ++cnt;
        } else {
            cnt = 1;
        }
        
        if ( max_cnt < cnt ) {
            max_cnt = cnt;
            res = a[i];
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
~~~

2. map을 사용하여 문제를 풀이

~~~ cpp
#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    map<long long, int> d;
    
    while ( cnt-- ) {
        long long x = 0;
        cin >> x;
        d[x] += 1;
    }

    int max = 0;
    long long res = 0;
    for ( auto &p : d ) {
        if ( p.second > max ) {
            max = p.second;
            res = p.first;
        } else if ( p.second == max && p.first < res ) {
            res = p.first;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
~~~