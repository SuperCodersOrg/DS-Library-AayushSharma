#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorCopyConstructor, CopyOneElement)
{
    Vector<int> a;

    a.push_back(10);

    Vector<int> b(a);

    EXPECT_EQ(b[0], 10);
}

TEST(VectorCopyConstructor, CopySize)
{
    Vector<int> a;

    for(int i = 0; i < 5; i++)
        a.push_back(i);

    Vector<int> b(a);

    EXPECT_EQ(b.Size(), 5);
}

TEST(VectorCopyConstructor, DeepCopy)
{
    Vector<int> a;

    a.push_back(10);

    Vector<int> b(a);

    b[0] = 99;

    EXPECT_EQ(a[0], 10);
    EXPECT_EQ(b[0], 99);
}

TEST(VectorCopyConstructor, ValidCapacityAfterCopy)
{
    Vector<int> a(25);

    for(int i = 0; i < 5; i++)
        a.push_back(i);

    Vector<int> b(a);

    EXPECT_EQ(b.Size(), a.Size());
    EXPECT_GE(b.Capacity(), b.Size());

    for(int i = 0; i < b.Size(); i++)
        EXPECT_EQ(b[i], a[i]);
}

TEST(VectorCopyConstructor, CopyEmptyVector)
{
    Vector<int> a;

    Vector<int> b(a);

    EXPECT_TRUE(b.isempty());
}