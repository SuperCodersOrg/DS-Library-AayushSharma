#include <gtest/gtest.h>
#include "Redislite.h"

TEST(SizeTest, InitiallyZero)
{
    redislite redis;

    EXPECT_EQ(redis.size(),0);
}

TEST(SizeTest, OneInsertion)
{
    redislite redis;

    redis.set("a","1");

    EXPECT_EQ(redis.size(),1);
}

TEST(SizeTest, MultipleInsertions)
{
    redislite redis;

    redis.set("a","1");
    redis.set("b","2");
    redis.set("c","3");

    EXPECT_EQ(redis.size(),3);
}

TEST(SizeTest, AfterDelete)
{
    redislite redis;

    redis.set("a","1");
    redis.del("a");

    EXPECT_EQ(redis.size(),0);
}

TEST(SizeTest, DuplicateKey)
{
    redislite redis;

    redis.set("a","1");
    redis.set("a","2");

    EXPECT_EQ(redis.size(),1);
}