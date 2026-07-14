#include <gtest/gtest.h>
#include "List.h"

TEST(LinkedListConstructor, DefaultConstructor)
{
    Linkedlist<int> ls;

    EXPECT_TRUE(ls.isempty());
}

TEST(LinkedListConstructor, SizeInitiallyZero)
{
    Linkedlist<int> ls;

    EXPECT_EQ(ls.Size(),0);
}

TEST(LinkedListConstructor, BeginInitiallyNull)
{
    Linkedlist<int> ls;

    EXPECT_EQ(ls.begin(),nullptr);
}

TEST(LinkedListConstructor, EndInitiallyNull)
{
    Linkedlist<int> ls;

    EXPECT_EQ(ls.end(),nullptr);
}

TEST(LinkedListConstructor, EmptyList)
{
    Linkedlist<int> ls;

    EXPECT_TRUE(ls.begin()==nullptr);
}