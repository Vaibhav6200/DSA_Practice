// Concepts
// (i) Constructor, Constructor Overloading
// (ii) Destructor
// (iii) Operator Overloading

#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int age;
    string gender;

    Student(){
        cout << "Default Constructor Called" << endl;
    }
    // Parameterised Constructor
    Student(string n, int a, string g){
        name = n;
        age = a;
        gender = g;
    }

    // When main function ends destructor will be called for each object
    ~Student(){
        cout << "Destructor Called" << endl;
    }

    // Operator Overloading
    bool operator == (Student &s){
        if(name == s.name && age == s.age && gender == s.gender)
            return true;
        return false;
    }

};

int main()
{
    // Student a;
    // a.name = "Vaibhav";
    // a.age = 20;
    // a.gender = "Male";

    Student a("Vaibhav", 20, "male");
    Student b;
    b=a;

    Student c("Abhay", 20, "male");
    if(a==c)
        cout << "Same Objects" << endl;
    else
        cout << "Different Objects" << endl;
    // cout << b.name << endl;
    // cout << b.age << endl;
    // cout << b.gender << endl;

    return 0;
}