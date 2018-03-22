10825번 국영수
------------

국어 점수가 같으면 영어 점수가 증가하는 순서로, 다르면 국어 점수가 감소하는 순서로 정렬하며  
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서대로 정렬합니다.  
그리고 모든 점수가 같을 경우에 이름이 사전 순으로 증가하는 순서로 정렬하여 문제를 해결해야 합니다.  

다른 해결 방법으로는, C++의 tuple을 사용하여 문제를 해결할 수 있습니다.  

1. sort Function의 comp를 직접 구현

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    int kor, eng, math;

    Person() {
        kor = 0;
        eng = 0;
        math = 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<Person> a(n);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
    }
    
    sort(a.begin(), a.end(), [](const Person &u, const Person &v) {
        if ( u.kor == v.kor ) {
            if ( u.eng == v.eng ) {
                if ( u.math == v.math ) {
                    return u.name < v.name;
                } else {
                    return u.math > v.math;
                }
            } else {
                return u.eng < v.eng;
            }
        } else {
            return u.kor > v.kor;
        }
    });
    
    for ( auto &p : a ) {
        cout << p.name << '\n';
    }
    
    return 0;
}
~~~

2. Tuple을 사용하여 구현

~~~ cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

struct Person {
    string name;
    int kor, eng, math;

    Person() {
        kor = 0;
        eng = 0;
        math = 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector<Person> a(n);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
    }

    sort(a.begin(), a.end(), [](const Person &u, const Person &v) {
        return (make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name));
    });

    for ( auto &p : a ) {
        cout << p.name << '\n';
    }

    return 0;
}
~~~