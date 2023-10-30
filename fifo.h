#pragma once
#include <iostream>

// FIFO with circular buffer
#define MAX_FIFO_SIZE 7
#define FIFO_BUFFER_SIZE (MAX_FIFO_SIZE + 1)

template <class T>
class arrayFifo {
public:

	arrayFifo(uint32_t rp = 0, uint32_t wp = 0)
	{
		mWritePtr = wp;
		mReadPtr = rp;
	};
	~arrayFifo() {};

	void decrementWritePointer(void)
	{
		mWritePtr--;
		mWritePtr = (mWritePtr > MAX_FIFO_SIZE) ? MAX_FIFO_SIZE : mWritePtr;
	}
	
	void incrementWritePointer(void)
	{
		mWritePtr++; // pointer now points to the next empty element in mBuff
		mWritePtr = (mWritePtr > MAX_FIFO_SIZE) ? 0 : mWritePtr;
	}
	
	void decrementReadPointer(void)
	{
		mReadPtr--; // mReadPtr is an unsigned int so it cannot become negative
		mReadPtr = (mReadPtr > MAX_FIFO_SIZE) ? MAX_FIFO_SIZE : mReadPtr;
	}
	
	void incrementReadPointer(void)
	{
		mReadPtr++;
		mReadPtr = (mReadPtr > MAX_FIFO_SIZE) ? 0 : mReadPtr;
	}

	void push_front(T val, bool force = false)	// push new value to the front of the queue
	{
		if (!isFull())  // if not full
		{
			decrementReadPointer();
			mBuff[mReadPtr] = val;
		}
		else
		{
			if (force == true)
			{
				mBuff[mWritePtr] = val;
				decrementReadPointer();
				decrementWritePointer();
			}
		}
	}

	void push_back(T val, bool force = false)	// Push new value to the back of the queue
	{
		if (!isFull())
		{
			mBuff[mWritePtr] = val; // the mWritePtrth index of mBuff becomes this val (writing to the end of the fifo)
			incrementWritePointer();
		}
		else
		{
			if (force == true)
			{
				mBuff[mWritePtr] = val;
				incrementReadPointer();
				incrementWritePointer();
			}
		}
	}

	T pop_front()
	{
		T val = 0;
		if (!isEmpty()) // this pointer points to the size member of the object
		{
			val = mBuff[mReadPtr];
			incrementReadPointer();
		}
		return val; // returns the value of the front element
	}

	T pop_back()
	{
		T val = 0;
		if (!isEmpty())
		{
			decrementWritePointer();
			val = mBuff[mWritePtr];
		}
		return val;
	}

	void clear(void)
	{
		mWritePtr = 0;
		mReadPtr = 0;
	}

	bool isEmpty(void) { return (mWritePtr == mReadPtr) ? true : false; }

	bool isFull(void) { return (MAX_FIFO_SIZE == size()); }

	uint32_t size()
	{
		if (mWritePtr == mReadPtr)
		{
			return 0;
		}
		else if (mWritePtr > mReadPtr)
		{
			return (mWritePtr - mReadPtr);
		}
		else
		{
			return FIFO_BUFFER_SIZE - (mReadPtr - mWritePtr);
		}
	}

	uint32_t getWPtr() { return mWritePtr; }

	uint32_t getRPtr() { return mReadPtr; }

private:
	T mBuff[FIFO_BUFFER_SIZE] = {};
	uint32_t mWritePtr = 0;
	uint32_t mReadPtr = 0;
};
