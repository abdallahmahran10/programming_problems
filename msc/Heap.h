

template<typename T>
class Heap
{
protected:
	T *heapArray;
	size_t capacity;
	size_t heapSize;
public:
	T *DefaultToReturnInFailure;
	
	Heap(int n, T *_default = NULL) :heapArray(new T[n]), capacity(n), heapSize(0), DefaultToReturnInFailure(_default)
	{
	}
	//
	T top(){ return heapArray[0]; }
	//
	int parent(int i){ return (i - 1) / 2; }
	//
	int left(int i){ return 2 * i + 1; }
	//
	int right(int i){ return 2 * i + 2; }
	//
	virtual bool compare(int l, int i) = 0;
	//
	void swapElments(int i, int j)
	{
		T tmp = heapArray[i];
		heapArray[i] = heapArray[j];
		heapArray[j] = tmp;
	}
	//
	void heapify(int i)
	{
		if(!heapSize)
			return;	
		int j = i, l = left(i), r = right(i);
		if (l < heapSize && compare(l, i))
			j = l;
		if (r < heapSize && compare(r, i))
			j = r;
		if (j != i)
		{
			swapElments(i, j);
			heapify(j);
		}
	}
	//
	T extractTop()
	{
		if (heapSize == 0 && DefaultToReturnInFailure != NULL)
			return *DefaultToReturnInFailure;
		if (heapSize == 1)
			return heapArray[--heapSize];
		T root = heapArray[0]; 
		heapArray[0] = heapArray[--heapSize];
		heapify(0);
		return root;
	}
	//
	void insert(T elm)
	{
		if (heapSize >= capacity)
			return;
		heapArray[heapSize++] = elm;
		fixHeap(heapSize-1);
	}
	//
	void fixHeap(size_t i)
	{
		// Fix the heap property if it is violated
		while (i && compare(i, parent(i)))
		{
			swapElments(i, parent(i));
			i = parent(i);
		}
	}
	//
	void deleteElement(int i)
	{
		if (--heapSize == i)
			return;
		heapArray[i] = heapArray[heapSize];
		heapify(i);
	}
	void decreaseKey(int i, T new_val)
	{
		heapArray[i] = new_val;
		fixHeap(i);
	}
};

template<typename T>
class MaxHeap : public Heap<T>
{
public:
	MaxHeap(int n) : Heap<T>(n)
	{}
	//
	bool compare(int i, int j)
	{
		return heapArray[i] > heapArray[j];
	}
};

template<typename T>
class MinHeap : public Heap<T>
{
public:
	MinHeap(int n) : Heap<T>(n)
	{}
	//
	bool compare(int i, int j)
	{
		return heapArray[i] < heapArray[j];
	}
};
