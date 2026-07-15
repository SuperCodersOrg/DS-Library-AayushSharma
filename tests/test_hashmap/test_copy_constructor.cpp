#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(CopyConstructorTest, CopySingleElement)
{
    HashMap<int,int> map1;
    map1.push(1,10);

    HashMap<int,int> map2(map1);

    EXPECT_EQ(map2.find(1)->Value,10);
}

TEST(CopyConstructorTest, CopyMultipleElements)
{
    HashMap<int,int> map1;

    for(int i=0;i<10;i++)
        map1.push(i,i*10);

    HashMap<int,int> map2(map1);

    for(int i=0;i<10;i++)
        EXPECT_EQ(map2.find(i)->Value,i*10);
}

TEST(CopyConstructorTest, DeepCopy)
{
    HashMap<int,int> map1;
    map1.push(1,10);

    HashMap<int,int> map2(map1);

    map2[1]=100;

    EXPECT_EQ(map1[1],10);
    EXPECT_EQ(map2[1],100);
}

TEST(CopyConstructorTest, CopyEmptyMap)
{
    HashMap<int,int> map1;
    HashMap<int,int> map2(map1);

    EXPECT_EQ(map2.find(1),nullptr);
}

TEST(CopyConstructorTest, CopyAfterRehash)
{
    HashMap<int,int> map1;

    for(int i=0;i<100;i++)
        map1.push(i,i);

    HashMap<int,int> map2(map1);

    EXPECT_EQ(map2.find(99)->Value,99);
}