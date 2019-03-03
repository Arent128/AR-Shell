#include "../src/Parenthesis.h"
#include "../src/dAmpersand.h"
#include "../src/dPipe.h"
#include "../src/SemiColon.h"
#include "../src/Executable.h"
#include "gtest/gtest.h"

TEST(ParenthesisTest, ConstructionTest)
{
  Parenthesis* testParen = new Parenthesis();
  Parenthesis* newParen = testParen;
  EXPECT_EQ(testParen, newParen); 
}

TEST(ParenthesisTest, CopyConstructionTest)
{
   SemiColon* testSemi = new SemiColon(new Executable("echo hello ",2), new Executable("echo World ",2));
   Parenthesis* testParen = new Parenthesis(testSemi);
   EXPECT_EQ(true, testParen->execute(0,1));
}

TEST(ParenthesisTest, PrecedenceTest)
{
   dAmpersand* testAmp1 = new dAmpersand(new Executable("echo A ", 2), new Executable("echo B ", 2));
   dAmpersand* testAmp2 = new dAmpersand(new Executable("echo C ", 2), new Executable("echo D ", 2));
   Parenthesis* testParen1 = new Parenthesis(testAmp1);
   Parenthesis* testParen2 = new Parenthesis(testAmp2);
   dPipe* testPipe = new dPipe(testParen1, testParen2);
   EXPECT_EQ(true, testPipe->execute(0,1));
}
