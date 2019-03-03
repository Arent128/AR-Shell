#include "../src/SemiColon.h"
#include "../src/dPipe.h"
#include "../src/dAmpersand.h"
#include "../src/Executable.h"
#include "gtest/gtest.h"

TEST(SemiColonTest, ConstructionTest)
{
    SemiColon* testSemi = new SemiColon();
    SemiColon* semiTest = testSemi;
    EXPECT_EQ(testSemi, semiTest);
}

TEST(SemiColonTest, CopyConstructionTest)
{
    SemiColon* testSemi = new SemiColon(new Executable("echo hello ", 2), new Executable("echo world ", 2));
    EXPECT_EQ(true, testSemi->execute(0,1));
}

TEST(SemiColonTest, AddCmdTest)
{
    SemiColon* testSemi = new SemiColon();
    testSemi->addLeftCmd(new Executable("echo hello ", 2));
    testSemi->addRightCmd(new Executable("echo world ", 2));
    EXPECT_EQ(true, testSemi->execute(0,1));
}

TEST(dPipeTest, ConstructionTest)
{
    dPipe* testPipe = new dPipe();
    dPipe* pipeTest = testPipe;
    EXPECT_EQ(testPipe, pipeTest);
}

TEST(dPipeTest, CopyConstructionTest)
{
    dPipe* testPipe = new dPipe(new Executable("echo hello ", 2), new Executable("echo world ", 2));
    EXPECT_EQ(true, testPipe->execute(0,1));
}

TEST(dPipeTest, AddCmdTest)
{
    dPipe* testPipe = new dPipe();
    testPipe->addLeftCmd(new Executable("echo hello ", 2));
    testPipe->addRightCmd(new Executable("echo world ", 2));
    EXPECT_EQ(true, testPipe->execute(0,1));
}

TEST(dAmpersandTest, ConstructionTest)
{
    dAmpersand* testAmp = new dAmpersand();
    dAmpersand* ampTest = testAmp;
    EXPECT_EQ(testAmp, ampTest);
}

TEST(dAmpersandTest, CopyConstructionTest)
{
    dAmpersand* testAmp = new dAmpersand(new Executable("echo hello ", 2), new Executable("echo world ", 2));
    EXPECT_EQ(true, testAmp->execute(0,1));
}

TEST(dAmpersandTest, AddCmdTest)
{
    dAmpersand* testAmp = new dAmpersand();
    testAmp->addLeftCmd(new Executable("echo hello ", 2));
    testAmp->addRightCmd(new Executable("echo world ", 2));
    EXPECT_EQ(true, testAmp->execute(0,1));
}


