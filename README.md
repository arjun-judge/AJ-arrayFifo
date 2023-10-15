# AJ-arrayFifo
 
This class uses a C++ array of pre-determined length to store values. Read and write pointers are used to pop from or push to the front or back of the buffer.

I use a template class so the array can store values of different data types depending on the need of the user. The constructor initialises the values of the pointers (default is 0, 0). The destructor is used to destroy the class objects that the constructor created i.e., releasing memory space taken up by objects.

The 4 functions that decrement/increment the read/write pointers are used to ensure the pointers loop around once they reach the front/back of the array (at which point if they increment/decrement any more it will not be in the array).

The push_front and push_back functions 
