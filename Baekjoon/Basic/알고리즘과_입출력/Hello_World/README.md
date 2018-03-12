2557번 Hello World
------------------

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    cout << "Hello World!" << '\n';

    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

int main() 
{
    printf("Hello World!\n");
    
    return 0;
}
~~~
