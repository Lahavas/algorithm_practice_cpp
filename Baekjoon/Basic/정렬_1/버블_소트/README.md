1377번 버블 소트
-------------

버블 소트의 원리를 이해하여 문제를 해결해야 합니다.  
버블 소트에서 Element는 한 칸씩 이동하며 정렬을 진행합니다.  
즉, 가장 많이 이동한 Element를 구하여 이동 횟수의 최댓값을 구하여 문제를 풀 수 있습니다.  

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
    
    vector<pair<int, int>> a(n);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    
    int res = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( res < a[i].second - i ) {
            res = a[i].second - i;
        }
    }
    
    cout << res + 1 << '\n';
    return 0;
}
~~~