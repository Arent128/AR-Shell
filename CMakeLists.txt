CMAKE_MINIMUM_REQUIRED(VERSION 2.0)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(ARshell
    src/main.cpp
    src/Input.cpp
    src/InputParser.cpp
    src/SemiColon.cpp
    src/dPipe.cpp
    src/dAmpersand.cpp
    src/Executable.cpp
    src/Parenthesis.cpp
    src/TestFunc.cpp
    src/OutputDirec.cpp
    src/OutputAppend.cpp
    src/InputDirec.cpp
    src/Pipe.cpp
)

ADD_EXECUTABLE(test
    tests/test.cpp
    tests/testExecutable.cpp
    tests/testParser.cpp
    tests/testInput.cpp
    tests/testConnector.cpp
    tests/testParenthesis.cpp
    tests/testFunc.cpp
    tests/testDirec.cpp
    src/Executable.cpp
    src/Input.cpp
    src/InputParser.cpp
    src/SemiColon.cpp
    src/dPipe.cpp
    src/dAmpersand.cpp
    src/Parenthesis.cpp
    src/TestFunc.cpp
    src/OutputDirec.cpp
    src/OutputAppend.cpp
    src/InputDirec.cpp
    src/Pipe.cpp
)

TARGET_LINK_LIBRARIES(ARshell gtest)
TARGET_COMPILE_DEFINITIONS(ARshell PRIVATE gtest_disable_pthreads=ON)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
