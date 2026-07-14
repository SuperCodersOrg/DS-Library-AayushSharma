#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorConstructor, DefaultConstructor)
{
    Vector<int> v;

    EXPECT_EQ(v.Size(), 0);
}

TEST(VectorConstructor, DefaultCapacityPositive)
{
    Vector<int> v;

    EXPECT_GT(v.Capacity(), 0);
}

TEST(VectorConstructor, ParameterizedConstructor)
{
    Vector<int> v(25);

    EXPECT_EQ(v.Capacity(), 25);
}

TEST(VectorConstructor, ParameterizedConstructorSizeZero)
{
    Vector<int> v(10);

    EXPECT_EQ(v.Size(), 0);
}

TEST(VectorConstructor, ConstructStringVector)
{
    Vector<std::string> v;

    EXPECT_TRUE(v.isempty());
}