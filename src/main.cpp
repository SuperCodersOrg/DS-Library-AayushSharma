#include<iostream>
#include "Vector.h"
#include "List.h"
#include "Hashmap.h"
#include "List.h"
using namespace std ;

class Student {
public:
    int id;

    Student() {}

    Student(int val) {
        id = val;
    }
    int formhash()const{
        return this->id;
    }
    bool operator==(const Student& other) const {
        return id == other.id;
    }

    bool operator!=(const Student& other) const {
        return !(*this == other);
    }
};
int main(){
Student s1(2);
Student s2(3);
Student s3(4);
Hashmap<Student,int>hs;
hs.insert(s1,2);
hs.insert(s2,3);
hs.insert(s3,4);
cout<<hs[s2]<<endl;
Hashmap<Student,int>hs2;
Student s4(100);
Student s5(200);
Student s6(300);
hs2.insert(s4,2);
hs2.insert(s5,3);
hs2.insert(s6,4);
cout<<hs2[s5]<<endl;
hs2=hs;
cout<<hs2[s1]<<endl;

return 0;
 
}