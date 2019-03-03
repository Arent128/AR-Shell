#include "../src/TestFunc.h"
#include "gtest/gtest.h"

TEST(TestFuncTests, ConstructionTest)
{
    TestFunc* testFunc = new TestFunc();
    TestFunc* funcTest = testFunc;
    EXPECT_EQ(testFunc, funcTest);
}

TEST(TestFuncTests, CopyConstructionTest)
{
    TestFunc* testFunc = new TestFunc("-e googletest ", 2);
    EXPECT_EQ(true, testFunc->execute(0,1));
}

TEST(TestFuncTests, ExecuteTest)
{
    TestFunc* testFunc = new TestFunc("-d tests/ ", 2);
    EXPECT_EQ(true, testFunc->execute(0,1));
}

TEST(TestFuncTests, ExecuteTest1)
{
    TestFunc* testFunc = new TestFunc("-f CMakeLists.txt ", 2);
    EXPECT_EQ(true, testFunc->execute(0,1));
}

TEST(TestFuncTests, ExecuteTest2)
{
    TestFunc* testFunc = new TestFunc("-f src/main.cpp ", 2);
    EXPECT_EQ(true, testFunc->execute(0,1));
}
