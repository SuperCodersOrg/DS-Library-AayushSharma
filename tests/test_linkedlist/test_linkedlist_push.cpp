#include <gtest/gtest.h>
#include "List.h"

TEST(LinkedListPush, PushOne)
{
    Linkedlist<int> ls;

    int x=10;
    ls.push(x);

    EXPECT_EQ(ls.Size(),1);
}

TEST(LinkedListPush, PushMultiple)
{
    Linkedlist<int> ls;

    for(int i=0;i<5;i++)
        ls.push(i);

    EXPECT_EQ(ls.Size(),5);
}

TEST(LinkedListPush, FirstElement)
{
    Linkedlist<int> ls;

    int x=15;
    ls.push(x);

    EXPECT_EQ(ls[0],15);
}

TEST(LinkedListPush, PreserveOrder)
{
    Linkedlist<int> ls;

    int a=1,b=2,c=3;

    ls.push(a);
    ls.push(b);
    ls.push(c);

    EXPECT_EQ(ls[2],3);
}

TEST(LinkedListPush, PushString)
{
    Linkedlist<std::string> ls;

    std::string s="Hello";

    ls.push(s);

    EXPECT_EQ(ls[0],"Hello");
}