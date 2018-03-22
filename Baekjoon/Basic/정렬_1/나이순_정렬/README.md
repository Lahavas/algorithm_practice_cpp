10814번 나이순 정렬
----------------

나이와 이름을 가입한 순서대로 정렬해야하는 문제입니다.  
나이가 같을 경우 가입 순서대로 정렬하고, 같지 않으면 나이가 어린 순서대로 정렬하는 방식으로 comp Function을 구현할 수 있습니다.  
sort Function의 comp를 직접 구현하는 방법 그리고 operator <를 구현하는 방법을 사용하여 문제를 해결할 수 있습니다.  

다른 방법으로는, 가입 순서를 따로 저장하지 않고 stable_sort를 이용하여 기존에 정렬된 상태에서 나이만을 비교하여 문제를 해결할 수 있습니다.  

1. Person struct와 sort의 comp Function을 직접 구현

~~~ cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person {
    int age;
    string name;
    int join;

    Person() {
        age = 0;
        join = 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<Person> a(n);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].age >> a[i].name;
        a[i].join = i;
    }
    
    sort(a.begin(), a.end(), [](const Person &u, const Person &v) {
            return (u.age == v.age ? u.join < v.join : u.age < v.age);
        });
    
    for ( auto &p : a ) {
        cout << p.age << ' ' << p.name << '\n';
    }
    
    return 0;
}
~~~

2. Person struct와 Operator < 의 Overloading을 구현

~~~ cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person {
    int age;
    string name;
    int join;

    Person() {
        age = 0;
        join = 0;
    }

    bool operator < (const Person &v) const {
        return (age == v.age ? join < v.join : age < v.age);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector<Person> a(n);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].age >> a[i].name;
        a[i].join = i;
    }

    sort(a.begin(), a.end());

    for ( auto &p : a ) {
        cout << p.age << ' ' << p.name << '\n';
    }

    return 0;
}
~~~

3. stable_sort를 사용하여 풀이

~~~ cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person {
    int age;
    string name;

    Person() {
        age = 0;
    }

    bool operator < (const Person &v) const {
        return (age < v.age);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector<Person> a(n);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].age >> a[i].name;
    }

    stable_sort(a.begin(), a.end());

    for ( auto &p : a ) {
        cout << p.age << ' ' << p.name << '\n';
    }

    return 0;
}
~~~