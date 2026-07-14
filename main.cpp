#include<iostream>
#include"Vector.h"
#include"List.h"
#include<sstream>
#include"Hashmap.h"
using namespace std ;
class Student
{
public:
    int roll;
    string name;

    Student(int r=0,string n="")
    {
        roll=r;
        name=n;
    }


    int formhash() const
    {
        return roll;
    }


    bool operator==(const Student& s) const
    {
        return roll == s.roll;
    }
};
int main()
{
    HashMap<Student,string> hm;


    Student s1(101,"Aayush");
    Student s2(102,"Rahul");
    Student s3(103,"Aayush");
    Student s4(104,"Rahul");

int* p = new int[5];
p[10] = 100;  // Out of bounds

    hm.push(s1,"C++");
    hm.push(s2,"DSA");

 HashMap<Student,string>hm1;
 hm1.push(s3,"python");
 hm1.push(s4,"go");
    cout << hm1[s3] << endl;
    hm1.pop(s3);
    cout << hm1[s4] << endl;
    hm1=hm;
    cout<<hm1[s1];


    return 0;
}