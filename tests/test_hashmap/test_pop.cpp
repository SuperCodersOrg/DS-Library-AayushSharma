#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(PopTest, RemoveSingleElement)
{
    HashMap<int,int> map;

    map.push(1,10);
    map.pop(1);

    EXPECT_EQ(map.find(1),nullptr);
}

TEST(PopTest, RemoveMiddle)
{
    HashMap<int,int> map;

    map.push(1,10);
    map.push(2,20);

    map.pop(1);

    EXPECT_EQ(map.find(1),nullptr);
    EXPECT_NE(map.find(2),nullptr);
}

TEST(PopTest, RemoveLast)
{
    HashMap<int,int> map;

    map.push(5,50);

    map.pop(5);

    EXPECT_EQ(map.find(5),nullptr);
}

TEST(PopTest, RemoveMissingKey)
{
    HashMap<int,int> map;

    map.pop(10);

    EXPECT_EQ(map.find(10),nullptr);
}

TEST(PopTest, RemoveAfterRehash)
{
    HashMap<int,int> map;

    for(int i=0;i<50;i++)
        map.push(i,i);

    map.pop(25);

    EXPECT_EQ(map.find(25),nullptr);
}