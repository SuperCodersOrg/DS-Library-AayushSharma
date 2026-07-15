#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(HashMapKeysTest, EmptyMap)
{
    HashMap<int,int> map;

    testing::internal::CaptureStdout();
    map.keys();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.empty());
}

TEST(HashMapKeysTest, SingleKey)
{
    HashMap<int,int> map;

    map.push(1,10);

    testing::internal::CaptureStdout();
    map.keys();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("1"),std::string::npos);
}

TEST(HashMapKeysTest, MultipleKeys)
{
    HashMap<int,int> map;

    map.push(1,10);
    map.push(2,20);
    map.push(3,30);

    testing::internal::CaptureStdout();
    map.keys();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("1"),std::string::npos);
    EXPECT_NE(output.find("2"),std::string::npos);
    EXPECT_NE(output.find("3"),std::string::npos);
}

TEST(HashMapKeysTest, AfterDeletion)
{
    HashMap<int,int> map;

    map.push(1,10);
    map.pop(1);

    testing::internal::CaptureStdout();
    map.keys();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("1"),std::string::npos);
}

TEST(HashMapKeysTest, AfterRehash)
{
    HashMap<int,int> map;

    for(int i=0;i<50;i++)
        map.push(i,i);

    testing::internal::CaptureStdout();
    map.keys();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("49"),std::string::npos);
}