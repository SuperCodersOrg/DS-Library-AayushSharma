#include <gtest/gtest.h>
#include "List.h"

TEST(LinkedListSize, InitiallyZero)
{
    Linkedlist<int> ls;

    EXPECT_EQ(ls.Size(),0);
}

TEST(LinkedListSize, AfterOnePush)
{
    Linkedlist<int> ls;

    int x=10;
    ls.push(x);

    EXPECT_EQ(ls.Size(),1);
}

TEST(LinkedListSize, AfterMultiplePush)
{
    Linkedlist<int> ls;

    for(int i=0;i<5;i++)
    {
        int x=i;
        ls.push(x);
    }

    EXPECT_EQ(ls.Size(),5);
}

TEST(LinkedListSize, AfterPop)
{
    Linkedlist<int> ls;

    int a=1,b=2;

    ls.push(a);
    ls.push(b);

    ls.pop();

    EXPECT_EQ(ls.Size(),1);
}

TEST(LinkedListSize, AfterDeleteAny)
{
    Linkedlist<int> ls;

    int a=1,b=2,c=3;

    ls.push(a);
    ls.push(b);
    ls.push(c);

    ls.delete_any(b);

    EXPECT_EQ(ls.Size(),2);
}