#include <gtest/gtest.h>
#include "List.h"

TEST(LinkedListPop, PopOne)
{
    Linkedlist<int> ls;

    int x=5;

    ls.push(x);
    ls.pop();

    EXPECT_TRUE(ls.isempty());
}

TEST(LinkedListPop, PopReducesSize)
{
    Linkedlist<int> ls;

    int a=1,b=2;

    ls.push(a);
    ls.push(b);

    ls.pop();

    EXPECT_EQ(ls.Size(),1);
}

TEST(LinkedListPop, PopKeepsFirst)
{
    Linkedlist<int> ls;

    int a=10,b=20;

    ls.push(a);
    ls.push(b);

    ls.pop();

    EXPECT_EQ(ls[0],10);
}

TEST(LinkedListPop, PopAll)
{
    Linkedlist<int> ls;

    int a=1,b=2;

    ls.push(a);
    ls.push(b);

    ls.pop();
    ls.pop();

    EXPECT_TRUE(ls.isempty());
}

TEST(LinkedListPop, PopEmptyThrows)
{
    Linkedlist<int> ls;

    EXPECT_THROW(ls.pop(),std::underflow_error);
}