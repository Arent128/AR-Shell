#include "../src/Input.h"
#include "gtest/gtest.h"

TEST(InputTest, ConstructionTest)
{
     Input* inputLine = new Input();
     Input* testLine = inputLine;
     EXPECT_EQ(inputLine, testLine);
}

TEST(InputTest, SimpleCmdTest)
{
     Input* inputLine = new Input("echo hello");
     inputLine->parse();
     inputLine->singleCmd();
     EXPECT_EQ(true, inputLine->execute(0,1)); 
}

TEST(InputTest, SimpleSemiColonTest)
{
   Input* inputLine = new Input("echo hello; echo hi ");
   inputLine->parse();
   inputLine->createTree();
   EXPECT_EQ(true, inputLine->execute(0,1)); 
}

TEST(InputTest, SimpledAmperandTest)
{
   Input* inputLine = new Input("echo hello &&  echo hi ");
   inputLine->parse();
   inputLine->createTree();
   EXPECT_EQ(true, inputLine->execute(0,1));
}

TEST(InputTest, SimplePipeTest)
{
   Input* inputLine = new Input("echo hello ||  echo hi ");
   inputLine->parse();
   inputLine->createTree();
   EXPECT_EQ(true, inputLine->execute(0,1));
}

TEST(InputTest, SimpleParenthesisTest)
{
   Input* inputLine = new Input("(echo A && echo B) || ls");
   inputLine->parse();
   inputLine->createTree();
   EXPECT_EQ(true, inputLine->execute(0,1));
}

