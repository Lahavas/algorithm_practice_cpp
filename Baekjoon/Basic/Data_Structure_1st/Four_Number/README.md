10824번 네 수
-----------

string to number 관련 함수를 사용하여 해결할 수 있습니다.  
stoi, stol, stoll 와 같은 함수들은 string header에 선언되어 있습니다.  
두 개의 string을 합칠 경우 정수의 범위가 long type으로 늘어나기 때문에 이 점을 주의해서 풀어야합니다.

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(c) + to_string(d);

    long result = stol(s1) + stol(s2);

    cout << result << endl;

    return 0;
}
~~~