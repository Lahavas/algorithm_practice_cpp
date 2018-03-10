2751번 수 정렬하기 2
-----------------

1. STL에서 제공하는 sort 함수 사용하기

~~~ cpp
#include <cstdio>
#include <algorithm>

constexpr int MAX = 1000000;

int a[MAX] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);
    for ( int i = 0; i < n; ++i ) {
        scanf("%d", &a[i]);
    }
    
    std::sort(a, a + n);
    
    for ( int i = 0; i < n; ++i ) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}
~~~

2. Quick Sort를 직접 구현

~~~ cpp
#include <cstdio>

constexpr int MAX = 1000000;

int a[MAX] = { 0 };

void swap(int &x, int &y) 
{
    int tmp = x;
    x = y;
    y = tmp;
}

int choosePivot(int low, int high) 
{
    return low + (high-low)/2;
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

void quicksort(int low, int high) 
{
    if ( low < high ) {
        int pivot = partition(low, high);
        quicksort(low, pivot-1);
        quicksort(pivot+1, high);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    for ( int i = 0; i < n; ++i ) {
        scanf("%d", &a[i]);
    }

    quicksort(0, n-1);

    for ( int i = 0; i < n; ++i ) {
        printf("%d\n", a[i]);
    }

    return 0;
}
~~~

3. Merge Sort를 직접 구현

~~~ cpp
#include <cstdio>

constexpr int MAX = 1000000;

int a[MAX] = { 0 };
int b[MAX] = { 0 };

void swap(int &x, int &y) 
{
    int tmp = x;
    x = y;
    y = tmp;
}

void merge(int start, int end) 
{
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = 0;

    while ( i <= mid && j <= end ) {
        if ( a[i] <= a[j] ) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while ( i <= mid ) {
        b[k++] = a[i++];
    }

    while ( j <= end ) {
        b[k++] = a[j++];
    }

    for ( int i = start; i <= end; ++i ) {
        a[i] = b[i - start];
    }
}

void mergesort(int start, int end) 
{
    if ( start == end ) {
        return;
    }

    int mid = (start + end) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);
    merge(start, end);
}

int main() 
{
    int n;
    scanf("%d", &n);

    for ( int i = 0; i < n; ++i ) {
        scanf("%d", &a[i]);
    }

    mergesort(0, n-1);

    for ( int i = 0; i < n; ++i ) {
        printf("%d\n", a[i]);
    }

    return 0;
}
~~~