#include <gtest/gtest.h>
#include "Hashmap.h"

TEST(HashFunctionTest, IntegerHash)
{
    Hashcode h;

    EXPECT_EQ(h.hash(10,4),2);
}

TEST(HashFunctionTest, CharacterHash)
{
    Hashcode h;

    EXPECT_EQ(h.hash('A',10),5);
}

TEST(HashFunctionTest, StringHash)
{
    Hashcode h;

    EXPECT_EQ(h.hash(std::string("abc"),10),4);
}

TEST(HashFunctionTest, EmptyString)
{
    Hashcode h;

    EXPECT_EQ(h.hash(std::string(""),5),0);
}

TEST(HashFunctionTest, LargeInteger)
{
    Hashcode h;

    EXPECT_EQ(h.hash(12345,100),45);
}