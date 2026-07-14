#include <gtest/gtest.h>
#include "List.h"

TEST(LinkedListAssignment, BasicAssignment)
{
    Linkedlist<int> a;

    int x=10;

    a.push(x);

    Linkedlist<int> b;

    b=a;

    EXPECT_EQ(b[0],10);
}

TEST(LinkedListAssignment, SizeCopied)
{
    Linkedlist<int> a;

    for(int i=0;i<5;i++)
    {
        int x=i;
        a.push(x);
    }

    Linkedlist<int> b;

    b=a;

    EXPECT_EQ(b.Size(),5);
}

TEST(LinkedListAssignment, DeepCopy)
{
    Linkedlist<int> a;

    int x=10;

    a.push(x);

    Linkedlist<int> b;

    b=a;

    b[0]=100;

    EXPECT_EQ(a[0],10);
    EXPECT_EQ(b[0],100);
}

TEST(LinkedListAssignment, SelfAssignment)
{
    Linkedlist<int> a;

    int x=5;

    a.push(x);

    a=a;

    EXPECT_EQ(a[0],5);
}

TEST(LinkedListAssignment, AssignEmptyList)
{
    Linkedlist<int> a;
    Linkedlist<int> b;

    int x=10;

    b.push(x);

    b=a;

    EXPECT_TRUE(b.isempty());
}