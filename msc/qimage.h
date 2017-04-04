
template<typename T>
class Queue1
{
	int mSize;
	queue<T> mQueue;

public:
	Queue1(int s) :mSize(s){}

	void push(T e)
	{
		if (mQueue.size() < mSize)
			mQueue.push(e);
	}

	bool size()
	{
		return mQueue.size();
	}

	bool empty()
	{
		return mQueue.empty();
	}

	void pop()
	{
		mQueue.pop(e);
	}

	T top()
	{
		return mQueue.top();
	}
};
