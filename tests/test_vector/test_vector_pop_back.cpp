#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorPopBack, PopOneElement)
{
    Vector<int> v;

    v.push_back(10);
    v.pop_back();

    EXPECT_TRUE(v.isempty());
}

TEST(VectorPopBack, PopReducesSize)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);

    v.pop_back();

    EXPECT_EQ(v.Size(),1);
}

TEST(VectorPopBack, PopKeepsFirstElement)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);

    v.pop_back();

    EXPECT_EQ(v[0],1);
}

TEST(VectorPopBack, PopUntilEmpty)
{
    Vector<int> v;

    for(int i=0;i<5;i++)
        v.push_back(i);

    while(!v.isempty())
        v.pop_back();

    EXPECT_TRUE(v.isempty());
}

TEST(VectorPopBack, PopAfterResize)
{
    Vector<int> v;

    for(int i=0;i<20;i++)
        v.push_back(i);

    v.pop_back();

    EXPECT_EQ(v.Size(),19);
}