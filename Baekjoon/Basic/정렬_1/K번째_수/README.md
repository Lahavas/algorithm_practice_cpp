11004번 K번째 수
--------------

Quick Sort는 Pivot을 이용하여 정렬하는 알고리즘으로, 이를 응용하면 K번째 수가 있는 부분에 대해서만 정렬을 진행할 수 있습니다.  
또 다른 방법은 STL에서 제공하는 nth_element Function을 통해 문제를 해결할 수 있습니다.

1. Quick Sort를 응용하여 정렬

~~~ cpp
#include <iostream>

using namespace std;

constexpr int MAX = 5000001;
long a[MAX] = { 0 };

void swap(int &x, int &y) 
{
    int tmp = x;
    x = y;
    y = tmp;
}

int choosePivot(int low, int high) 
{
    return low + (high - low) / 2;
}

int partition(int low, int high) 
{
    int pivotIndex = choosePivot(low, high);
    int pivotValue = a[pivotIndex];
    swap(a[pivotIndex], a[high]);
    
    int storeIndex = low;
    for ( int i = low; i < high; ++i ) {
        if ( a[i] < pivotValue ) {
            swap(a[i], a[storeIndex]);
            storeIndex += 1;
        }
    }
    swap(a[storeIndex], a[high]);
    
    return storeIndex;
}

void quicksort(int low, int high, int k) 
{
    if ( low < high ) {
        int pivot = partition(low, high);
        if ( pivot < k ) {
            quicksort(pivot + 1, high, k);
        } else {
            quicksort(low, pivot - 1, k);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    int k = 0;
    cin >> n >> k;
    k -= 1;

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }

    quicksort(0, n - 1, k);
    cout << a[k] << '\n';

    return 0;
}
~~~

2. nth_element 함수를 사용하여 정렬

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    int k = 0;
    cin >> n >> k;
    k -= 1;
    
    vector<long> a(n, 0);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    
    nth_element(a.begin(), a.begin() + k, a.end());
    cout << a[k] << '\n';
    
    return 0;
}
~~~