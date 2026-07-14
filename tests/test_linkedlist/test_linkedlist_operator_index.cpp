#include <gtest/gtest.h>
#include "List.h"

TEST(LinkedListIndex, FirstElement)
{
    Linkedlist<int> ls;

    int x=10;

    ls.push(x);

    EXPECT_EQ(ls[0],10);
}

TEST(LinkedListIndex, LastElement)
{
    Linkedlist<int> ls;

    int a=1,b=2,c=3;

    ls.push(a);
    ls.push(b);
    ls.push(c);

    EXPECT_EQ(ls[2],3);
}

TEST(LinkedListIndex, ModifyElement)
{
    Linkedlist<int> ls;

    int x=5;

    ls.push(x);

    ls[0]=100;

    EXPECT_EQ(ls[0],100);
}

TEST(LinkedListIndex, StringElement)
{
    Linkedlist<std::string> ls;

    std::string s="Hello";

    ls.push(s);

    EXPECT_EQ(ls[0],"Hello");
}

TEST(LinkedListIndex, OutOfRange)
{
    Linkedlist<int> ls;

    EXPECT_THROW(ls[0],std::out_of_range);
}