#include "../src/InputDirec.h"
#include "../src/OutputDirec.h"
#include "../src/OutputAppend.h"
#include "../src/Pipe.h"
#include "../src/Executable.h"
#include <gtest/gtest.h>

TEST(OutputDirecTest, ConstructionTest)
{
    Executable* testExecutable = new Executable("echo A ", 2);
    OutputDirec* testOut = new OutputDirec(-2);
    testOut->Connector::addCmd(testExecutable);
    testOut->addOutFile("test1");
    OutputDirec* outTest = testOut;
    EXPECT_EQ(outTest, testOut);
}

TEST(OutputDirecTest, ExecuteTest)
{
    Executable* testExecutable = new Executable("echo A ", 2);
    OutputDirec* testOut = new OutputDirec(-2);
    testOut->Connector::addCmd(testExecutable);
    testOut->addOutFile("test1");
    EXPECT_EQ(true, testOut->execute(0,1));
    Executable* rmExe = new Executable("rm test1 ", 2);
    rmExe->execute(0,1);
}

TEST(OutputAppendTest, ConstructionTest)
{ 
    Executable* testExecutable = new Executable("echo A ", 2);
    OutputAppend* testApp = new OutputAppend(-2);
    testApp->Connector::addCmd(testExecutable);
    testApp->addOutFile("test1");
    OutputAppend* appTest = testApp;
    EXPECT_EQ(appTest, testApp);
}

TEST(OutputAppendTest, ExecuteTest)
{

    Executable* testExecutable = new Executable("echo A ", 2);
    OutputAppend* testApp = new OutputAppend(-2);
    testApp->Connector::addCmd(testExecutable);
    testApp->addOutFile("test1");
    EXPECT_EQ(true, testApp->execute(0,1));
    Executable* rmExe = new Executable("rm test1 ", 2);
    rmExe->execute(0,1);
}

TEST(InputDireTest, ConstructionTest)
{ 
    Executable* testExecutable = new Executable("sort ", 1);
    InputDirec* testIn = new InputDirec(-2);
    testIn->Connector::addCmd(testExecutable);
    testIn->addOutFile("test1");
    InputDirec* inTest = testIn;
    EXPECT_EQ(inTest, testIn);
}

TEST(InputDirecTest, ExecuteTest)
{

    Executable* testExecutable1 = new Executable("ls ", 1);
    OutputDirec* testOut = new OutputDirec(-2);
    testOut->Connector::addCmd(testExecutable1);
    testOut->addOutFile("test1");
    testOut->execute(0,1);
    Executable* testExecutable2 = new Executable("sort ", 1);
    InputDirec* testIn = new InputDirec(-2);
    testIn->Connector::addCmd(testExecutable2);
    testIn->addOutFile("test1");
    EXPECT_EQ(true, testIn->execute(0,1));
    Executable* rmExe = new Executable("rm test1 ", 2);
    rmExe->execute(0,1);
}

TEST(PipeTest, ConstructionTest)
{
    Pipe* testPipe = new Pipe(-3);
    Pipe* pipeTest = testPipe;
    EXPECT_EQ(testPipe, pipeTest);
}

TEST(PipeTest, ExecuteTest)
{
    Pipe* testPipe = new Pipe(-3);
    testPipe->addLeftCmd(new Executable("cat CMakeLists.txt ", 2));
    testPipe->addRightCmd(new Executable("sort ", 1));
    EXPECT_EQ(true, testPipe->execute(0,1));
}
