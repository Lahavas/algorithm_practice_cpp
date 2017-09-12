2557번 Hello World
------------------

1. iostream 사용

~~~ cpp
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    cout << "Hello World!" << endl;

    return 0;
}
~~~

2. cstdio 사용

~~~ cpp
#include <cstdio>

int main() {
    printf("Hello World!\n");
    
    return 0;
}
~~~
