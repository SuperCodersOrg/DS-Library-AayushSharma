#include <gtest/gtest.h>
#include "Vector.h"
#include <string>

class Student
{
public:
    int roll;
    std::string name;

    Student(int r = 0, std::string n = "")
        : roll(r), name(n) {}

    bool operator==(const Student& other) const
    {
        return roll == other.roll;
    }
};

TEST(VectorUserDefined, AllOperations)
{
    Vector<Student> v;

    // Constructor
    EXPECT_TRUE(v.isempty());
    EXPECT_EQ(v.Size(), 0);
    EXPECT_GE(v.Capacity(), 1);

    // Push
    Student s1(101, "Aayush");
    Student s2(102, "Rahul");
    Student s3(103, "Rohit");

    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    EXPECT_FALSE(v.isempty());
    EXPECT_EQ(v.Size(), 3);

    // operator[]
    EXPECT_EQ(v[0].roll, 101);
    EXPECT_EQ(v[1].roll, 102);
    EXPECT_EQ(v[2].roll, 103);

    EXPECT_EQ(v[0].name, "Aayush");
    EXPECT_EQ(v[1].name, "Rahul");
    EXPECT_EQ(v[2].name, "Rohit");

    // Modify element
    v[1].name = "Modified";

    EXPECT_EQ(v[1].name, "Modified");

    // Copy Constructor
    Vector<Student> copy(v);

    EXPECT_EQ(copy.Size(), 3);
    EXPECT_EQ(copy[0].roll, 101);
    EXPECT_EQ(copy[1].roll, 102);
    EXPECT_EQ(copy[2].roll, 103);

    // Deep Copy
    copy[0].name = "Copied";

    EXPECT_EQ(v[0].name, "Aayush");
    EXPECT_EQ(copy[0].name, "Copied");

    // Assignment Operator
    Vector<Student> assign;

    assign = v;

    EXPECT_EQ(assign.Size(), 3);
    EXPECT_EQ(assign[2].roll, 103);

    // Deep Copy after assignment
    assign[2].name = "Changed";

    EXPECT_EQ(v[2].name, "Rohit");
    EXPECT_EQ(assign[2].name, "Changed");

    // Pop
    assign.pop_back();

    EXPECT_EQ(assign.Size(), 2);
    EXPECT_EQ(assign[0].roll, 101);
    EXPECT_EQ(assign[1].roll, 102);

    // Self Assignment
    assign = assign;

    EXPECT_EQ(assign.Size(), 2);
    EXPECT_EQ(assign[0].roll, 101);
    EXPECT_EQ(assign[1].roll, 102);

    // Out of Range
    EXPECT_THROW(assign[5], std::out_of_range);

    // Pop remaining elements
    assign.pop_back();
    assign.pop_back();

    EXPECT_TRUE(assign.isempty());

    // Pop on Empty Vector
    EXPECT_THROW(assign.pop_back(), std::underflow_error);
}