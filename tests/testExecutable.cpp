#include "../src/Executable.h"
#include "gtest/gtest.h"

TEST(ExecutableTest, ConstructionTest)
{
    Executable* testExecutable = new Executable();
    Executable* tmpExecutable = testExecutable;
    EXPECT_EQ(testExecutable, tmpExecutable);
}

TEST(ExecutableTest, SimpleExecuteTest)
{
   Executable* testExecutable = new Executable("echo hello ", 2);
   EXPECT_EQ(true, testExecutable->execute(0,1));
}

TEST(ExecutableTest, FailedExecuteTest)
{
    Executable* testExecutable = new Executable("mdkir test ", 2);
    EXPECT_EQ(false, testExecutable->execute(0,1));
}

