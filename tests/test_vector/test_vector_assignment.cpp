#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorAssignment, BasicAssignment)
{
    Vector<int> a;

    a.push_back(10);

    Vector<int> b;

    b = a;

    EXPECT_EQ(b[0], 10);
}

TEST(VectorAssignment, SizeCopied)
{
    Vector<int> a;

    for(int i = 0; i < 5; i++)
        a.push_back(i);

    Vector<int> b;

    b = a;

    EXPECT_EQ(b.Size(), 5);
}

TEST(VectorAssignment, DeepCopy)
{
    Vector<int> a;

    a.push_back(10);

    Vector<int> b;

    b = a;

    b[0] = 100;

    EXPECT_EQ(a[0], 10);
    EXPECT_EQ(b[0], 100);
}

TEST(VectorAssignment, SelfAssignment)
{
    Vector<int> a;

    a.push_back(1);

    a = a;

    EXPECT_EQ(a[0], 1);
}

TEST(VectorAssignment, ValidCapacityAfterAssignment)
{
    Vector<int> a(20);

    for(int i = 0; i < 5; i++)
        a.push_back(i);

    Vector<int> b;

    b = a;

    EXPECT_EQ(b.Size(), a.Size());
    EXPECT_GE(b.Capacity(), b.Size());

    for(int i = 0; i < b.Size(); i++)
        EXPECT_EQ(b[i], a[i]);
}