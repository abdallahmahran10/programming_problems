/*
* Author: Abdallah Mahran
* file: Queue.h
*/
#ifndef QUEUE_H
#define QUEUE_H
/******************* Includes *******************/

/******************* Queue Cass *******************/
template<typename T>
class Queue
{
	T *mQueue;
	int mSize;
	int mFront, mRear;
public:
	Queue(int s):mSize(s), mFront(-1), mRear(-1), mQueue(NULL)
	{
		mQueue = new T[mSize];
	}
	~Queue()
	{ 
		delete mQueue;
		mQueue = NULL;
	}
	
	void enqueue(T e)
	{
		if(full())
		{
			std::cout<< "ERROR: Queue is full!" << std::endl;
			return;
		}
		//
		if(empty())
		{
			mRear = mFront = 0;
		} else
		{
			mRear = (mRear + 1) % mSize;
		}
		mQueue[mRear] = e;
	}
	//
	void dequeue()
	{
		if(empty())
		{
			std::cout<< "ERROR: Queue is empty!" << std::endl;
			return;
		}
		if(mFront == mRear)
			mFront = mRear = -1;
		else 
			mFront =  (mFront + 1) % mSize;
	}
	
	T front()
	{
		return mQueue[mFront];
	}

	bool full()
	{
		return (mRear +1) % mSize == mFront;
	}
	
	bool empty()
	{
		return mFront == -1 && mRear == -1;
	}
};

#endif //QUEUE_H
