#include "../src/InputParser.h"
#include "gtest/gtest.h"

TEST(InputParser, ConstructionTest)
{
    InputParser* testParser = new InputParser();
    InputParser* checkParser = new InputParser();
    EXPECT_NE(checkParser, testParser);
}

TEST(InputParser, SimpleParseTest)
{
    InputParser* testParser = new InputParser();
    std::string testInput = "this is a test";
    std::vector<std::string>* testVec = testParser->parse(testInput);
    EXPECT_EQ(testVec->at(0), "this");
    EXPECT_EQ(testVec->at(1), "is");
    EXPECT_EQ(testVec->at(2), "a");
    EXPECT_EQ(testVec->at(3), "test");
}

TEST(InputParser, ConnectorParseTest)
{ 
    InputParser* testParser = new InputParser();
    std::string testInput = "echo hello; echo world && echo test";
    std::vector<std::string>* testVec = testParser->parse(testInput);
    EXPECT_EQ(testVec->at(0), "echo");
    EXPECT_EQ(testVec->at(1), "hello");
    EXPECT_EQ(testVec->at(2), ";");
    EXPECT_EQ(testVec->at(3), "echo");
    EXPECT_EQ(testVec->at(4), "world");
    EXPECT_EQ(testVec->at(5), "&&");
    EXPECT_EQ(testVec->at(6), "echo");
    EXPECT_EQ(testVec->at(7), "test");
}

TEST(InputParser, ConnectorCheckFunction)
{
    InputParser* testParser = new InputParser();
    std::string testInput1 = "echo hello; echo world";
    std::string testInput2 = "echo hello";
    std::string testInput3 = "echo hello && echo world";
    EXPECT_EQ(3, testParser->connectorCheck(testInput1));
}
