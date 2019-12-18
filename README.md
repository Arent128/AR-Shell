# AR-Shell
This project is a C++ implementation of a terminal that emulates the Bourne Again Shell (BASH). It has most of the functionality of that the BASH terminal would have, although various implemenations of this version differ from the the actual BASH terminal.

### Installing

By following the installation set of instruction, you will be able to access and interact with AR-Shell by following the following steps: 

Perform git clone command to clone the repository project onto your host
```
$ git clone --recurse-submodules https://github.com/Arent/AR-Shell.git
```
Following the previous step, change directories into the folder where the program executable is at
```
$ cd AR-Shell
```
Create the executables for the project by running cmake.
```
$ cmake CMakeLists.txt
$ make
```
Run the executable program that was created after the previous step.
```
$ ./ARshell
```
While in the shell type exit as follows to exit the shell.
```
$ exit
```
### Test
By executing the test program, this provides a series of test with multiple and various inputs. 
```
$ ./test
```

### Encountered Bugs
Through the development of our program, I encountered bugs that negativity impact the reliability of the program. The following are a list of problems we’ve encountered:

- Certain inputs involving parathesis will fail. ie: )(   (echo)(echo)
- Placing multiple connectors without arguements results in a seg fault.
- Multiple input redirection will cause the intial file to be used as the file in which input is taken from.
- Multiple output apphends redirectors cause the output from any given command to be placed in the initial and final final listed.
- If a file does not exist when calling multiple input redirections, files that have been opened will still be created. Where as per bash the files would have never been created if a file does not exist.
- When inputting the connectors in the command line, it is space sensitive so it would not work unless there are spaces in the front or back of the connectors
-test inputs that have spaces within their path will fail.
- Not able to use single quotation to interpret string literals
- When inputting "test" into the rshell system, the rshell will interpret "test" as a Test Command. Thus, it will not allow us to create a test directory without thinking its a Test Command
