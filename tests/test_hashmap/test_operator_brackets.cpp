#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(BracketTest, InsertUsingBracket)
{
    HashMap<int,int> map;

    map[1]=10;

    EXPECT_EQ(map[1],10);
}

TEST(BracketTest, UpdateUsingBracket)
{
    HashMap<int,int> map;

    map[2]=20;
    map[2]=100;

    EXPECT_EQ(map[2],100);
}

TEST(BracketTest, DefaultInitialization)
{
    HashMap<int,int> map;

    EXPECT_EQ(map[10],0);
}

TEST(BracketTest, MultipleKeys)
{
    HashMap<int,int> map;

    map[1]=10;
    map[2]=20;

    EXPECT_EQ(map[1],10);
    EXPECT_EQ(map[2],20);
}

TEST(BracketTest, StringValues)
{
    HashMap<int,std::string> map;

    map[5]="Hello";

    EXPECT_EQ(map[5],"Hello");
}