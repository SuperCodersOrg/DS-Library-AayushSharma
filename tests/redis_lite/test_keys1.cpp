#include <gtest/gtest.h>
#include "Redislite.h"

TEST(KeysTest, EmptyKeys)
{
    redislite redis;

    testing::internal::CaptureStdout();

    redis.keys();

    std::string output=testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.empty());
}

TEST(KeysTest, OneKey)
{
    redislite redis;

    redis.set("one","1");

    testing::internal::CaptureStdout();

    redis.keys();

    std::string output=testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("one"),std::string::npos);
}

TEST(KeysTest, MultipleKeys)
{
    redislite redis;

    redis.set("a","1");
    redis.set("b","2");
    redis.set("c","3");

    testing::internal::CaptureStdout();

    redis.keys();

    std::string output=testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("a"),std::string::npos);
    EXPECT_NE(output.find("b"),std::string::npos);
    EXPECT_NE(output.find("c"),std::string::npos);
}

TEST(KeysTest, AfterDelete)
{
    redislite redis;

    redis.set("x","10");
    redis.del("x");

    testing::internal::CaptureStdout();

    redis.keys();

    std::string output=testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("x"),std::string::npos);
}

TEST(KeysTest, AfterManyInsertions)
{
    redislite redis;

    for(int i=0;i<20;i++)
        redis.set(std::to_string(i),"v");

    testing::internal::CaptureStdout();

    redis.keys();

    std::string output=testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("19"),std::string::npos);
}