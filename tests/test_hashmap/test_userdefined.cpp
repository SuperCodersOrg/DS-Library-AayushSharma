#include <gtest/gtest.h>
#include "Hashmap.h"

class Student
{
public:
    int roll;
    std::string name;

    Student(int r = 0, std::string n = "")
        : roll(r), name(n) {}

    int formhash() const
    {
        return roll;
    }

    bool operator==(const Student& other) const
    {
        return roll == other.roll;
    }
};

TEST(UserDefinedTest, InsertObject)
{
    HashMap<Student,int> map;

    Student s(1,"Aayush");

    map.push(s,100);

    EXPECT_EQ(map.find(s)->Value,100);
}

TEST(UserDefinedTest, MultipleObjects)
{
    HashMap<Student,int> map;

    Student s1(1,"A");
    Student s2(2,"B");
    Student s3(3,"C");

    map.push(s1,10);
    map.push(s2,20);
    map.push(s3,30);

    EXPECT_EQ(map.find(s2)->Value,20);
}

TEST(UserDefinedTest, UpdateExistingKey)
{
    HashMap<Student,int> map;

    Student s(1,"A");

    map.push(s,10);
    map.push(s,100);

    EXPECT_EQ(map.find(s)->Value,100);
}

TEST(UserDefinedTest, OperatorBracket)
{
    HashMap<Student,int> map;

    Student s(5,"John");

    map[s]=500;

    EXPECT_EQ(map[s],500);
}

TEST(UserDefinedTest, RehashWithObjects)
{
    HashMap<Student,int> map;

    for(int i=0;i<100;i++)
    {
        Student s(i,"Student");
        map.push(s,i);
    }

    Student last(99,"Student");

    EXPECT_EQ(map.find(last)->Value,99);
}