10825번 국영수
------------

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    int kor;
    int eng;
    int math;
};

int main()
{
    int n = 0;
    cin >> n;
    
    vector<Person> a(n);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
    }
    
    sort(a.begin(), a.end(), [](const Person &u, const Person &v) {
        if ( u.kor > v.kor ) {
            return true;
        } else if ( u.kor == v.kor ) {
            if ( u.eng < v.eng ) {
                return true;
            } else if ( u.eng == v.eng ) {
                if ( u.math > v.math ) {
                    return true;
                } else if ( u.math == v.math ) {
                    return u.name < v.name;
                }
            }
        }
        return false;
    });
    
    for ( auto &p : a ) {
        cout << p.name << '\n';
    }
    
    return 0;
}
~~~