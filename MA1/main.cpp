/* Attributes demonstrated by the code that I would call poor:
1. The queue.h function declerations should be moved into a queue.cpp file
2. There are is no pragma once statement on the original main.cpp file which may lead to linker errors
3. Since the queue size is set as 10, there is no need for the constructor to take an argument for size,
as it can just be declared inside the constructor with a size of 10.
4. There is no general constructor for the queue class that takes no arguments, only a copy constructor with queue (int size).
5. The queue has a fixed size of 10, so it cannot be used to represent lists greater than 10 elements. I think if the queue was implemented as a linked list which can continue to be added on to instead of an array, this would have been fixed. 
*/

#include <iostream>
#include <cstdlib>
#include"testQueue.h"

// main function
int main()
{
    // call your test functions here!
   
    sizeTestCase();
    isEmptyTestCase();
    isFulltestCase();
    dequeueTestCase1();
    dequeueTestCase2();
    enqueueTestCase1();
    enqueueTestCase2();
    peekTestCase1();
    peekTestCase2();
    return 0;
}

