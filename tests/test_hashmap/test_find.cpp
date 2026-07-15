#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(FindTest, ExistingKey)
{
    HashMap<int,int> map;
    map.push(1,10);

    EXPECT_NE(map.find(1),nullptr);
}

TEST(FindTest, NonExistingKey)
{
    HashMap<int,int> map;

    EXPECT_EQ(map.find(100),nullptr);
}

TEST(FindTest, CorrectValue)
{
    HashMap<int,int> map;

    map.push(7,700);

    EXPECT_EQ(map.find(7)->Value,700);
}

TEST(FindTest, MultipleInsertions)
{
    HashMap<int,int> map;

    for(int i=0;i<20;i++)
        map.push(i,i);

    EXPECT_EQ(map.find(15)->Value,15);
}

TEST(FindTest, FindAfterUpdate)
{
    HashMap<int,int> map;

    map.push(1,1);
    map.push(1,10);

    EXPECT_EQ(map.find(1)->Value,10);
}