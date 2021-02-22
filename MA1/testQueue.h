#ifndef TESTQUEUE_H
#define TESTQUEUE_H


/*For each unit test you are required to construct a comment block with the information described in the background section 
“What is a test case?”, and implement a test function for the corresponding test case. Each test function must have a function
declaration that is placed in a file called testQueue.h all test function definitions
and comment blocks must be placed in a file called testQueue.cpp. 

Call your test functions from main (). 
At this point do NOT fix the bugs discovered! This will be done as part of the next step! Place the results of each test case,
 i.e. pass or fail in the same comment block as the test case comment block.*/

//This means we want these tests to be self-contained. They do not accept any arguments and do not return any results. All setup and evaluation for the test is done inside the function.
 void sizeTestCase(void);

 void isEmptyTestCase (void);

 void isFulltestCase(void);

 void dequeueTestCase1(void);
 void dequeueTestCase2(void);

 void enqueueTestCase1(void);
 void enqueueTestCase2(void);

 void peekTestCase1(void);
 void peekTestCase2(void);

 #endif