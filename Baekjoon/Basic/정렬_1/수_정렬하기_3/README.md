10989번 수 정렬하기 3
-----------------

이와 같이 정렬해야하는 숫자가 굉장히 크고, 입력값의 범위가 작은 문제는 각 입력값을 Index로 하는 배열을 사용하여 문제를 해결할 수 있습니다.  
입력값의 범위가 10000보다 작거나 같은 자연수이므로, 크기가 10000인 배열을 만들어 풀이하면  
따로 정렬을 하지 않고 O(N + 10000)번만에 문제를 해결할 수 있습니다.  

~~~ cpp
#include <cstdio>

constexpr int MAX = 10001;

int cnt[MAX] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    for ( int i = 0; i < n; ++i ) {
        int num = 0;
        scanf("%d", &num);
        ++cnt[num];
    }
    
    for ( int i = 1; i < MAX; ++i ) {
        if ( cnt[i] > 0 ) {
            for ( int j = 0; j < cnt[i]; ++j ) {
                printf("%d\n", i);
            }
        }
    }
    
    return 0;
}
~~~