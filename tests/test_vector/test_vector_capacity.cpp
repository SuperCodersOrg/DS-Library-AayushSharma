#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorCapacity, DefaultCapacityPositive)
{
    Vector<int> v;
    EXPECT_GT(v.Capacity(), 0);
}

TEST(VectorCapacity, ParameterizedCapacity)
{
    Vector<int> v(20);
    EXPECT_EQ(v.Capacity(), 20);
}

TEST(VectorCapacity, CapacityAfterPush)
{
    Vector<int> v;

    int cap = v.Capacity();

    v.push_back(10);

    EXPECT_GE(v.Capacity(), cap);
}

TEST(VectorCapacity, CapacityAfterResize)
{
    Vector<int> v(2);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    EXPECT_GT(v.Capacity(), 2);
}

TEST(VectorCapacity, CapacityNeverLessThanSize)
{
    Vector<int> v;

    for(int i = 0; i < 20; i++)
        v.push_back(i);

    EXPECT_GE(v.Capacity(), v.Size());
}