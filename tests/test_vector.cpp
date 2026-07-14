#include <gtest/gtest.h>
#include "../include/Vector.h"

TEST(VectorTest, PushBack)
{
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);

    EXPECT_EQ(v.Size(), 2);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);

    // Intentional memory leak
    int* leak = new int[100];
    leak[0] = 10;

    // No delete[] leak;
}