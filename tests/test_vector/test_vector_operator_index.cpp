#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorIndex, FirstElement)
{
    Vector<int> v;

    v.push_back(10);

    EXPECT_EQ(v[0], 10);
}

TEST(VectorIndex, LastElement)
{
    Vector<int> v;

    for(int i = 0; i < 5; i++)
        v.push_back(i);

    EXPECT_EQ(v[4], 4);
}

TEST(VectorIndex, ModifyElement)
{
    Vector<int> v;

    v.push_back(1);

    v[0] = 100;

    EXPECT_EQ(v[0], 100);
}

TEST(VectorIndex, MultipleAccess)
{
    Vector<int> v;

    for(int i = 0; i < 10; i++)
        v.push_back(i);

    EXPECT_EQ(v[5], 5);
}

TEST(VectorIndex, StringVector)
{
    Vector<std::string> v;

    v.push_back("Hello");

    EXPECT_EQ(v[0], "Hello");
}