#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person {
    int age;
    string name;
    int join;
};

int main()
{
    int n = 0;
    cin >> n;
    
    vector<Person> a(n);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].age >> a[i].name;
        a[i].join = i;
    }
    
    sort(a.begin(), a.end(),
        [](const Person &u, const Person &v) {
            return (u.age == v.age ? u.join < v.join : u.age < v.age);
        });
    
    for ( auto &p : a ) {
        cout << p.age << ' ' << p.name << '\n';
    }
    
    return 0;
}