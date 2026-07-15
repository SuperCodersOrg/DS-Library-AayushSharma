#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(RehashTest, InsertMany)
{
    HashMap<int,int> map;

    for(int i=0;i<100;i++)
        map.push(i,i);

    EXPECT_EQ(map.find(99)->Value,99);
}

TEST(RehashTest, ValuesRemainCorrect)
{
    HashMap<int,int> map;

    for(int i=0;i<50;i++)
        map.push(i,i*10);

    EXPECT_EQ(map.find(25)->Value,250);
}

TEST(RehashTest, SearchAfterRehash)
{
    HashMap<int,int> map;

    for(int i=0;i<80;i++)
        map.push(i,i);

    EXPECT_NE(map.find(60),nullptr);
}

TEST(RehashTest, UpdateAfterRehash)
{
    HashMap<int,int> map;

    for(int i=0;i<80;i++)
        map.push(i,i);

    map.push(50,500);

    EXPECT_EQ(map.find(50)->Value,500);
}

TEST(RehashTest, RemoveAfterRehash)
{
    HashMap<int,int> map;

    for(int i=0;i<80;i++)
        map.push(i,i);

    map.pop(20);

    EXPECT_EQ(map.find(20),nullptr);
}