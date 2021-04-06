#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world\n", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("\n", echo(1,test_val));
}

TEST(EchoTest, NewlineString) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello\n"; test_val[2] = "world";
    EXPECT_EQ("hello\n world\n", echo(3,test_val));
}

TEST(EchoTest, Spaces) {
    char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "   ";
    EXPECT_EQ("   \n", echo(2, test_val));
}

TEST(EchoTest, SpecialChars) {
    char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "\t\t\n";
    EXPECT_EQ("\t\t\n\n", echo(2, test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
