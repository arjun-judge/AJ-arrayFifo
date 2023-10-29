# AJ-arrayFifo

Essentially a double-ended queue class in C++.

IN FIFO.H:

This class uses a C++ array of pre-determined length to store values. Read and write pointers are used to pop from or push to the front or back of the queue.

I use a template class so the array can store values of different data types depending on the need of the user. The constructor initialises the values of the pointers (default is 0, 0). The destructor is used to destroy the class objects that the constructor created i.e., releasing memory space taken up by objects.

The 4 methods that decrement/increment the read/write pointers are used to ensure the pointers loop around once they reach the front/back of the array (at which point if they increment/decrement any more it will not be in the array).

The push_front() method decrements the read pointer and then sets the value at this index equal to the pushed value. Note that when we decrement the read pointer, it automatically loops to the end of the array if required. If the queue is full and the boolean 'force' is true, this means we force the pushed value to the front of the queue and shift the rest of the values along one space. The effect of this is that the last element in the queue (the value at mWritePtr - 1) is removed from the queue. This process happens by setting the value of the write pointer element equal to the pushed value and then decrementing each pointer.

The push_back() method sets the value at the write pointer index equal to the pushed value, and then increments the write pointer. Note that when we increment the write pointer, it automatically loops to the start of the array if required. If the queue is full and the boolean 'force' is true, this means we force the pushed value to the back of the queue and shift the rest of the values along one space. The effect of this is that the first element in the queue (the value at mReadPtr) is removed from the FIFO. This process happens by setting the value of the write pointer element equal to the pushed value and then incrementing each pointer.

The pop_front() and pop_back() methods return the first element and the final element in the queue respectively, with these elements being removed from the queue.

The clear() method sets the pointer values equal (note these do not have to be zero - they can be any value between 0 and MAX_FIFO_SIZE as long as they are the same).

The isEmpty() method returns true if the two pointers have equal value (uses ternary operator).

The isFull() method returns true if the size of the FIFO is equal to the MAX_FIFO_SIZE.

The size() method determines the size of the queue using the values of the pointers. If wp = rp, then the queue must be empty. If wp > rp, then the size is simply the difference of the two. If wp < rp, then the size is the size of the whole array subtract the difference between rp and wp. For example, if MAX_FIFO_SIZE is 7, then FIFO_BUFFER_SIZE is 8 which means the mBuff array has 8 elements. Consider the case where rp = 5 and wp = 2. The length of the FIFO must be 8 - (5 - 2) = 5 (because the FIFO loops).

mBuff, mWritePtr and mReadPtr are private class members. The data type for mBuff array is T (class template).


IN FIFO.CPP:

The first line initialises an arrayFifo class object called my_fifo, where the array stores values of uint8_t data type. The initial values of rp and wp are 3.

The first for loop gives the size of the FIFO and the current rp and wp values before pushing a value to the back of the FIFO for each loop.

The second for loop gives the values of rp and wp before incrementing rp with each loop. By the end of the loop, wp should equal rp so the size of the FIFO should return 0.

MORE EXAMPLES TO COME.
