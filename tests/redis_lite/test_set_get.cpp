#include <gtest/gtest.h>
#include "Redislite.h"

TEST(SetGetTest, InsertSingleKey)
{
    redislite redis;

    redis.set("name","Aayush");

    EXPECT_EQ(redis.get("name"),"Aayush");
}

TEST(SetGetTest, UpdateExistingKey)
{
    redislite redis;

    redis.set("name","A");
    redis.set("name","B");

    EXPECT_EQ(redis.get("name"),"B");
}

TEST(SetGetTest, MultipleKeys)
{
    redislite redis;

    redis.set("a","1");
    redis.set("b","2");
    redis.set("c","3");

    EXPECT_EQ(redis.get("b"),"2");
}

TEST(SetGetTest, EmptyValue)
{
    redislite redis;

    redis.set("empty","");

    EXPECT_EQ(redis.get("empty"),"");
}

TEST(SetGetTest, LongString)
{
    redislite redis;

    std::string s(1000,'x');

    redis.set("long",s);

    EXPECT_EQ(redis.get("long"),s);
}