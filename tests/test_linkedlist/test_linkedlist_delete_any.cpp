#include <gtest/gtest.h>
#include "List.h"

TEST(LinkedListDelete, DeleteHead)
{
    Linkedlist<int> ls;

    int a=1,b=2;

    ls.push(a);
    ls.push(b);

    ls.delete_any(a);

    EXPECT_EQ(ls[0],2);
}

TEST(LinkedListDelete, DeleteTail)
{
    Linkedlist<int> ls;

    int a=1,b=2;

    ls.push(a);
    ls.push(b);

    ls.delete_any(b);

    EXPECT_EQ(ls.Size(),1);
}

TEST(LinkedListDelete, DeleteMiddle)
{
    Linkedlist<int> ls;

    int a=1,b=2,c=3;

    ls.push(a);
    ls.push(b);
    ls.push(c);

    ls.delete_any(b);

    EXPECT_EQ(ls[1],3);
}

TEST(LinkedListDelete, DeleteMissing)
{
    Linkedlist<int> ls;

    int a=1,b=5;

    ls.push(a);

    ls.delete_any(b);

    EXPECT_EQ(ls.Size(),1);
}

TEST(LinkedListDelete, DeleteOnlyNode)
{
    Linkedlist<int> ls;

    int a=10;

    ls.push(a);

    ls.delete_any(a);

    EXPECT_TRUE(ls.isempty());
}