#include <gtest/gtest.h>
#include "List.h"

TEST(LinkedListIsEmpty, EmptyList)
{
    Linkedlist<int> ls;

    EXPECT_TRUE(ls.isempty());
}

TEST(LinkedListIsEmpty, AfterPush)
{
    Linkedlist<int> ls;

    int x=10;
    ls.push(x);

    EXPECT_FALSE(ls.isempty());
}

TEST(LinkedListIsEmpty, PushThenPop)
{
    Linkedlist<int> ls;

    int x=10;

    ls.push(x);
    ls.pop();

    EXPECT_TRUE(ls.isempty());
}

TEST(LinkedListIsEmpty, DeleteOnlyElement)
{
    Linkedlist<int> ls;

    int x=5;

    ls.push(x);
    ls.delete_any(x);

    EXPECT_TRUE(ls.isempty());
}

TEST(LinkedListIsEmpty, MultipleElements)
{
    Linkedlist<int> ls;

    int a=1,b=2;

    ls.push(a);
    ls.push(b);

    EXPECT_FALSE(ls.isempty());
}