#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorPushBack, PushOneElement)
{
    Vector<int> v;

    v.push_back(10);

    EXPECT_EQ(v.Size(),1);
    EXPECT_EQ(v[0],10);
}

TEST(VectorPushBack, PushMultipleElements)
{
    Vector<int> v;

    for(int i=0;i<10;i++)
        v.push_back(i);

    EXPECT_EQ(v.Size(),10);
}

TEST(VectorPushBack, OrderMaintained)
{
    Vector<int> v;

    v.push_back(5);
    v.push_back(8);

    EXPECT_EQ(v[0],5);
    EXPECT_EQ(v[1],8);
}

TEST(VectorPushBack, ResizeAutomatically)
{
    Vector<int> v(2);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    EXPECT_GT(v.Capacity(),2);
}

TEST(VectorPushBack, PushStrings)
{
    Vector<std::string> v;

    v.push_back("Aayush");

    EXPECT_EQ(v[0],"Aayush");
}