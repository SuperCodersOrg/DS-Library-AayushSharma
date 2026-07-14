#include <gtest/gtest.h>
#include "List.h"

TEST(LinkedListCopyConstructor, CopyOneNode)
{
    Linkedlist<int> a;

    int x=10;

    a.push(x);

    Linkedlist<int> b(a);

    EXPECT_EQ(b[0],10);
}

TEST(LinkedListCopyConstructor, CopySize)
{
    Linkedlist<int> a;

    for(int i=0;i<5;i++)
    {
        int x=i;
        a.push(x);
    }

    Linkedlist<int> b(a);

    EXPECT_EQ(b.Size(),5);
}

TEST(LinkedListCopyConstructor, DeepCopy)
{
    Linkedlist<int> a;

    int x=10;

    a.push(x);

    Linkedlist<int> b(a);

    b[0]=100;

    EXPECT_EQ(a[0],10);
    EXPECT_EQ(b[0],100);
}

TEST(LinkedListCopyConstructor, CopyEmptyList)
{
    Linkedlist<int> a;

    Linkedlist<int> b(a);

    EXPECT_TRUE(b.isempty());
}

TEST(LinkedListCopyConstructor, PreserveOrder)
{
    Linkedlist<int> a;

    int x=1,y=2,z=3;

    a.push(x);
    a.push(y);
    a.push(z);

    Linkedlist<int> b(a);

    EXPECT_EQ(b[0],1);
    EXPECT_EQ(b[1],2);
    EXPECT_EQ(b[2],3);
}