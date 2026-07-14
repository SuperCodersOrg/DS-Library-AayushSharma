#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorIsEmpty, EmptyVector)
{
    Vector<int> v;
    EXPECT_TRUE(v.isempty());
}

TEST(VectorIsEmpty, AfterPush)
{
    Vector<int> v;

    v.push_back(10);

    EXPECT_FALSE(v.isempty());
}

TEST(VectorIsEmpty, AfterPushPop)
{
    Vector<int> v;

    v.push_back(10);
    v.pop_back();

    EXPECT_TRUE(v.isempty());
}

TEST(VectorIsEmpty, MultipleElements)
{
    Vector<int> v;

    for(int i = 0; i < 5; i++)
        v.push_back(i);

    EXPECT_FALSE(v.isempty());
}

TEST(VectorIsEmpty, PopTillEmpty)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);

    v.pop_back();
    v.pop_back();

    EXPECT_TRUE(v.isempty());
}