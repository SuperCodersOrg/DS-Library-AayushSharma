#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(ConstructorTest, EmptyMapFind)
{
    HashMap<int,int> map;

    EXPECT_EQ(map.find(1),nullptr);
}

TEST(ConstructorTest, PushAfterConstruction)
{
    HashMap<int,int> map;

    map.push(1,10);

    EXPECT_EQ(map.find(1)->Value,10);
}

TEST(ConstructorTest, DifferentType)
{
    HashMap<std::string,int> map;

    map.push("abc",5);

    EXPECT_EQ(map.find("abc")->Value,5);
}

TEST(ConstructorTest, CharKey)
{
    HashMap<char,int> map;

    map.push('A',10);

    EXPECT_EQ(map.find('A')->Value,10);
}

TEST(ConstructorTest, FloatValue)
{
    HashMap<int,float> map;

    map.push(1,2.5f);

    EXPECT_FLOAT_EQ(map.find(1)->Value,2.5f);
}