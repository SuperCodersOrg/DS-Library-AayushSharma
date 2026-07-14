#include <gtest/gtest.h>
#include "List.h"
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

TEST(LinkedListUserDefined, AllOperations)
{
    Linkedlist<Student> ls;

    // Constructor
    EXPECT_TRUE(ls.isempty());
    EXPECT_EQ(ls.Size(), 0);

    // Push
    Student s1(101, "Aayush");
    Student s2(102, "Rahul");
    Student s3(103, "Rohit");

    ls.push(s1);
    ls.push(s2);
    ls.push(s3);

    EXPECT_FALSE(ls.isempty());
    EXPECT_EQ(ls.Size(), 3);

    // operator[]
    EXPECT_EQ(ls[0].roll, 101);
    EXPECT_EQ(ls[1].roll, 102);
    EXPECT_EQ(ls[2].roll, 103);

    EXPECT_EQ(ls[0].name, "Aayush");
    EXPECT_EQ(ls[1].name, "Rahul");
    EXPECT_EQ(ls[2].name, "Rohit");

    // begin()
    EXPECT_NE(ls.begin(), nullptr);
    EXPECT_EQ(ls.begin()->value.roll, 101);

    // Copy Constructor
    Linkedlist<Student> copy(ls);

    EXPECT_EQ(copy.Size(), 3);
    EXPECT_EQ(copy[0].roll, 101);
    EXPECT_EQ(copy[1].roll, 102);
    EXPECT_EQ(copy[2].roll, 103);

    // Deep Copy
    copy[0].name = "Modified";

    EXPECT_EQ(ls[0].name, "Aayush");
    EXPECT_EQ(copy[0].name, "Modified");

    // Assignment Operator
    Linkedlist<Student> assign;
    assign = ls;

    EXPECT_EQ(assign.Size(), 3);
    EXPECT_EQ(assign[1].roll, 102);

    // delete_any()
    assign.delete_any(s2);

    EXPECT_EQ(assign.Size(), 2);
    EXPECT_EQ(assign[0].roll, 101);
    EXPECT_EQ(assign[1].roll, 103);

    // pop()
    assign.pop();

    EXPECT_EQ(assign.Size(), 1);
    EXPECT_EQ(assign[0].roll, 101);

    // Delete last element
    assign.delete_any(s1);

    EXPECT_TRUE(assign.isempty());

    // end()
    EXPECT_EQ(assign.end(), nullptr);

    // Out of range
    EXPECT_THROW(assign[0], std::out_of_range);

    // Pop on empty list
    EXPECT_THROW(assign.pop(), std::underflow_error);
}