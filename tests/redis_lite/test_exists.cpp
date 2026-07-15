#include <gtest/gtest.h>
#include "Redislite.h"

TEST(ExistsTest, ExistingKey)
{
    redislite redis;

    redis.set("a","1");

    EXPECT_TRUE(redis.exists("a"));
}

TEST(ExistsTest, MissingKey)
{
    redislite redis;

    EXPECT_FALSE(redis.exists("abc"));
}

TEST(ExistsTest, AfterDelete)
{
    redislite redis;

    redis.set("a","1");

    redis.del("a");

    EXPECT_FALSE(redis.exists("a"));
}

TEST(ExistsTest, MultipleKeys)
{
    redislite redis;

    redis.set("x","1");
    redis.set("y","2");

    EXPECT_TRUE(redis.exists("y"));
}

TEST(ExistsTest, EmptyMap)
{
    redislite redis;

    EXPECT_FALSE(redis.exists("nothing"));
}