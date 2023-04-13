There are four source files in total. Here is a brief overview of each of the files.

1. MyListArr.cpp 

This file contains the array based implementation of list. It consists of 
a template class named MyList which has three constructors (as per instructions), one destructors, 
13 other public functions and one function for printing the list as needed. Thsi file does not
contain any main function.

2. MyListLL.cpp 

This file contains the linked-list based implementation of list. It implements a doubly-linked-list.
It consists of a template class named MyList which has three constructors (as per instructions), one 
destructors, 13 other public functions and one function for printing the list as needed. This file 
does not contain any main function. 

3. list_main.cpp

This file contains a main function for demostrating the implementations. There are two lines on top
of this file which include the previous two files. When of them is uncommented and other is commented
that specific implementation can be tested. All input/output are based on File I/O

4. LRUcache.cpp

This file implements a generic LRUcache class. It supports a constructor and get() and put() method.
There is an extra generic class named data which holds the key-value pair. Since list is used everywhere,
most operations require linear time which could have been augmented by Binary Searcg Tree or equivalent
data structures. All I/O in main function are based on File I/O.