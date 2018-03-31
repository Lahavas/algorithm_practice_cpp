1991번 트리 순회
--------------

재귀 함수를 이용하여 Preorder, Inorder, Postorder를 구현하는 문제입니다.  
배열을 사용하여 이진 트리를 구현하고, 이를 탐색하는 방법으로 문제를 해결할 수 있습니다.  

~~~ cpp
#include <iostream>

using namespace std;

constexpr int NODE_SIZE = 26;

int a[NODE_SIZE][2] = { 0 };

void preorder(int x)
{
    if ( x == -1 ) {
        return;
    }

    cout << (char)(x + 'A');
    preorder(a[x][0]);
    preorder(a[x][1]);
}

void inorder(int x)
{
    if ( x == -1 ) {
        return;
    }

    inorder(a[x][0]);
    cout << (char)(x + 'A');
    inorder(a[x][1]);
}

void postorder(int x)
{
    if ( x == -1 ) {
        return;
    }

    postorder(a[x][0]);
    postorder(a[x][1]);
    cout << (char)(x + 'A');
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 0; i < n; ++i ) {
        char x = '\0', y = '\0', z = '\0';
        cin >> x >> y >> z;
        
        x -= 'A';
        
        if ( y == '.' ) {
            a[x][0] = -1;
        } else {
            a[x][0] = y - 'A';
        }

        if ( z == '.' ) {
            a[x][1] = -1;
        } else {
            a[x][1] = z - 'A';
        }
    }
    
    preorder(0);
    cout << '\n';

    inorder(0);
    cout << '\n';

    postorder(0);
    cout << '\n';

    return 0;
}
~~~