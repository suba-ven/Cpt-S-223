#include "testQueue.h"
#include "queue.h"


/*Test ID: Size of queue check -SQC
Unit: queue::size ()
Description: test to determine if queue::size () returns the correct value of added elements
steps:  1.Construct an empty queue object2
        2.Add two elements to the queue
        3.Conditionally evaluate the valued returned by queue::size()
    Test data: size = 2
Precondition: queue object is empty
Postcondition: queue object contains two elements, so size is 2
Expected result:  size is 2, two is returned
Actual result: size is 2, two is returned
Status: passed*/

 void sizeTestCase(void){
    std:: cout<<"\nSize Test Case: Generated new queue"<<std::endl;
     queue* a = new queue(10);
     a->enqueue(5);
     a->enqueue(7);
     int b = a->size();
     std::cout<<"The size of the queue is: "<<b<<std::endl;
 }

/*Test ID: Empty queue check -EQC
Unit: queue::isEmpty ()
Description: test to determine if queue::isEmpty () prints empty message if a queue object is empty
Test steps:  1.Construct an empty queue object2
        2.Invoke queue::isEmpty ()
        3.Conditionally evaluate the valued returned by queue::isEmpty ()Test data: size = 0P
Precondition: queue object is empty
Postcondition: queue object is still empty
Expected result: queue is empty;empty message printed
Actual result: queue is empty; empty message printed
Status: passed*/
 void isEmptyTestCase (void){
     std:: cout<<"\nIs Empty Test Case: Generated new queue"<<std::endl;
     queue* a = new queue(10);
     bool b = a->isEmpty();
     if(b)
        std::cout<<"The queue is empty"<<b<<std::endl;
    else
        std::cout<<"The queue is not empty "<<b<<std::endl;
    
 }

/*Test ID: Full queue check -FQC
Unit: queue::isFull ()
Description: test to determine if queue::isFull () prints full message if a queue object is full
Test steps:  1.Construct an empty queue object2
        2.Invoke queue::isEmpty ()
        3.Conditionally evaluate the valued returned by queue::isFull ()
Test data: size = 10P
Precondition: queue object is empty
Postcondition: queue object is full
Expected result: queue is full; full message printed
Actual result: queue is full; fullmessage printed
Status: passed*/
 void isFulltestCase(void){
std:: cout<<"\nIs Full Test Case: Generated new queue"<<std::endl;
 queue* a = new queue(10);
 for(int i = 0; i<10; i++){
     a->enqueue(i);
 }
 bool b = a->isFull();
     if(b==false)
        std::cout<<"The queue is full"<<b<<std::endl;
    else
        std::cout<<"The queue is not full "<<b<<std::endl;

 }

/*Test ID: Dequeue check1 -DQC1
Unit: queue::dequeue ()
Description: test to determine if dequeue function works by adding and removing an element
Test steps:  1.Construct an empty queue object
        2.enqueue an element
        3. dequeue the element
    Test data: size = 1P
Precondition: queue object is empty
Postcondition: queue object is empty
Expected result: successfully dequed
Actual result: element is successfully dequeued
Status: passed*/
 void dequeueTestCase1(void){
     std:: cout<<"\nDequeue Test Case 1: Generated new queue"<<std::endl;
 queue* a = new queue(10);
//dequeue into a queue with at least one element
 a->enqueue(4);
 a->dequeue();

 }

 /*Test ID: Dequeue check2 -DQC2
Unit: queue::dequeue ()
Description: test to determine if dequeue function works by removing an element from an epmpty queue
Test steps:  1.Construct an empty queue object
        3. dequeue the element, evaluate if the correct overflow error message is printed
    Test data: size = 0P
Precondition: queue object is empty
Postcondition: queue object is empty
Expected result: no dequeue occurs, error message prints
Actual result: no dequeue occurs, error message prints
Status: passed*/
 void dequeueTestCase2(void){
     std:: cout<<"\nDequeue Test Case 2: Generated new queue"<<std::endl;
 queue* a = new queue(10);
//dequeue into an empty queue, should be an error
 a->dequeue();

 }

/*Test ID: Enqueue check1 -DQC1
Unit: queue::enqueue ()
Description: test to determine if enqueue function works by adding an element to an empty list
Test steps:  1.Construct an empty queue object
        3. enqueue on element, evaluate if the addition was successful
    Test data: size = 1P
Precondition: queue object is empty
Postcondition: queue object contains one element
Expected result: enqueue occurs, one element is now in queue
Actual result: enqueue occurs, one element is now in queue
Status: passed*/
 void enqueueTestCase1(void){
     std:: cout<<"\nEnqueue Test Case 1: Generated new queue"<<std::endl;
 queue* a = new queue(10);
//enqueue into an empty queue
 a->enqueue(1);

 }

 /*Test ID: Enqueue check2 -EQC2
Unit: queue::enqueue ()
Description: test to determine if enqueue function works by adding an element to an empty list
Test steps:  1.Construct an empty queue object
        2. fill the queue to size 10
        3. enqueue on element, evaluate if the addition was successful
    Test data: size = 10P
Precondition: queue object is empty
Postcondition: queue object is full
Expected result: enqueue doesn't occur, error message prints
Actual result: enqueue occurs, one more element is now in queue
Status: failed*/
 void enqueueTestCase2(void){
     std:: cout<<"\nEnqueue Test Case 2: Generated new queue"<<std::endl;
 queue* a = new queue(10);
//enqueue into a full queue
  for(int i = 1; i<11; i++){
     a->enqueue(i);
 }
 a->enqueue(11);
 }

/*Test ID: peek check1 -PTC1
Unit: queue::peek ()
Description: test to determine if peek function works with an empty queue
Test steps:  1.Construct an empty queue object
        3. call peek function
    Test data: size = 1P
Precondition: queue object is empty
Postcondition: queue object is empty
Expected result: no peekk occurs, error message printed
Actual result: no peekk occurs, error message printed
Status: passed*/
 void peekTestCase1(void){
std:: cout<<"\nPeek Test Case 1: Generated new queue"<<std::endl;
 queue* a = new queue(10);
//test with an empty queue
int b = a->peek();
std::cout<<"The next element is: "<<b<<std::endl;
//should display 0 to show success
 }

/*Test ID: peek check2 -PTC2
Unit: queue::peek ()
Description: test to determine if peek function works with a nonempty queue
Test steps:  1.Construct an empty queue object
        3. fill queue
        3. call peek function
    Test data: size = 1P
Precondition: queue object is empty
Postcondition: queue object is  full
Expected result: peek occurs successfully
Actual result: peek occurs successfully
Status: passed*/
 void peekTestCase2(void){
std:: cout<<"\nGPeek Test Case 2: enerated new queue"<<std::endl;
 queue* a = new queue(10);
for(int i = 1; i<11; i++){
     a->enqueue(i);
 }
//test with a non emptyqueue
int b = a->peek();
std::cout<<"The next element is: "<<b<<std::endl;
 }