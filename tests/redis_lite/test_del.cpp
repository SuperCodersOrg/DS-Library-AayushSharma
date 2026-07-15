#include <gtest/gtest.h>
#include "Redislite.h"

TEST(DeleteTest, DeleteExistingKey)
{
    redislite redis;

    redis.set("a","10");
    redis.del("a");

    EXPECT_FALSE(redis.exists("a"));
}

TEST(DeleteTest, DeleteMissingKey)
{
    redislite redis;

    redis.del("xyz");

    EXPECT_FALSE(redis.exists("xyz"));
}

TEST(DeleteTest, DeleteOneOfMany)
{
    redislite redis;

    redis.set("a","1");
    redis.set("b","2");

    redis.del("a");

    EXPECT_TRUE(redis.exists("b"));
}

TEST(DeleteTest, DeleteTwice)
{
    redislite redis;

    redis.set("a","1");

    redis.del("a");
    redis.del("a");

    EXPECT_FALSE(redis.exists("a"));
}

TEST(DeleteTest, SizeAfterDelete)
{
    redislite redis;

    redis.set("a","1");
    redis.set("b","2");

    redis.del("a");

    EXPECT_EQ(redis.size(),1);
}