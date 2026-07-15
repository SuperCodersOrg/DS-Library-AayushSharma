#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(AssignmentTest, BasicAssignment)
{
    HashMap<int,int> map1;
    map1.push(1,10);

    HashMap<int,int> map2;
    map2=map1;

    EXPECT_EQ(map2.find(1)->Value,10);
}

TEST(AssignmentTest, MultipleElements)
{
    HashMap<int,int> map1;

    for(int i=0;i<20;i++)
        map1.push(i,i);

    HashMap<int,int> map2;
    map2=map1;

    EXPECT_EQ(map2.find(15)->Value,15);
}

TEST(AssignmentTest, SelfAssignment)
{
    HashMap<int,int> map;

    map.push(1,10);

    map=map;

    EXPECT_EQ(map.find(1)->Value,10);
}

TEST(AssignmentTest, DeepCopy)
{
    HashMap<int,int> map1;

    map1.push(1,10);

    HashMap<int,int> map2;
    map2=map1;

    map2[1]=100;

    EXPECT_EQ(map1[1],10);
}

TEST(AssignmentTest, AssignEmptyMap)
{
    HashMap<int,int> map1;
    HashMap<int,int> map2;

    map2=map1;

    EXPECT_EQ(map2.find(1),nullptr);
}