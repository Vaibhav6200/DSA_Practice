#include<iostream>
using namespace std;


template <typename T>
T Max(T a, T b){
    return (a>b ? a : b);
}

template <typename T1, typename T2>
void func(T1 a, T2 b){
    cout << a << " " << b << endl;
}

template<typename T2>
T2 Min(T2 a, T2 b){
    return (a<b ? a : b);
}


class Person{
    public:
    string name;
    int age;

    // if we do not overload this less than operator then compiler will not know how to compare between 2 persons in "Min" function
    bool operator<(auto &p1){
        return this->age < p1.age;
    }
};

ostream &operator<<(ostream &os, Person &p){
    os << p.name;
    return os;
}

int main()
{
    // template with only 1 datatype
    cout << Max<int>(5, 3) << endl;
    cout << Max(5, 3) << endl;
    cout << Max(15.4, 3.2) << endl;
    cout << Max('V', 'P') << endl;

    // template with 2 datatypes
    func<int, double>(5, 3.9);
    func('V', 20);

    // calling for template on our own user defined datatype
    Person p1{"vaibhav", 20};
    Person p2{"Suhani", 7};
    Person p3 = Min(p1, p2);
    cout << p3.name << endl;

    func(p1, p2);   // this will give us error unless we overload insertion operator

    return 0;
}