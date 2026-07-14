#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorSize, DefaultSizeIsZero)
{
    Vector<int> v;
    EXPECT_EQ(v.Size(), 0);
}

TEST(VectorSize, SizeAfterOnePush)
{
    Vector<int> v;
    v.push_back(10);

    EXPECT_EQ(v.Size(), 1);
}

TEST(VectorSize, SizeAfterMultiplePush)
{
    Vector<int> v;

    for(int i = 0; i < 10; i++)
        v.push_back(i);

    EXPECT_EQ(v.Size(), 10);
}

TEST(VectorSize, SizeAfterPop)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.pop_back();

    EXPECT_EQ(v.Size(), 1);
}

TEST(VectorSize, SizeAfterPushAndPop)
{
    Vector<int> v;

    for(int i = 0; i < 5; i++)
        v.push_back(i);

    v.pop_back();
    v.pop_back();

    EXPECT_EQ(v.Size(), 3);
}