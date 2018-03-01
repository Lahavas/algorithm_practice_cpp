11656번 접미사 배열
----------------

string의 c_str 함수, substr 함수, cstring의 strcmp 함수, algorithm의 sort 함수를 잘 이해하고 있어야합니다.  
vector 자료 구조는 자주 사용되므로 추가적인 학습이 필요합니다.  

~~~ cpp
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> vt;

    int size = s.size();

    for ( int i = 0; i < size; i++ ) {
        vt.push_back(i);
    }

    sort(vt.begin(), vt.end(), [&s] (int u, int v) {
        return strcmp(s.c_str() + u, s.c_str() + v) < 0;
    });

    for ( auto &x : vt ) {
        cout << s.substr(x) << endl;
    }

    return 0;
}
~~~