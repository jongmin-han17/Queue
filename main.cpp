//Written by Jongmin Han
//Circular Queue implementation in C++
#include <iostream>
using namespace std;

class Queue
{
public:
	Queue(int size);
	~Queue();
	bool IsEmpty();
	bool IsFull();
	void Enque(int num);
	int Deque();
private:
	int mFront;
	int mRear;
	int mSize;
	int* mArr;
};

Queue::Queue(int size)
	: mSize(size)
	, mFront(0)
	, mRear(0)
{
	mArr = new int[mSize];
}

Queue::~Queue()
{
	delete[] mArr;
}

bool Queue::IsEmpty()
{
	return mRear == mFront;
}

bool Queue::IsFull()
{
	return mFront == (mRear + 1) % mSize;
}

void Queue::Enque(int num)
{
	if (IsFull())
	{
		cout << "Full\n";
	}
	else
	{
		mRear++;
		mRear = mRear % mSize;
		mArr[mRear] = num;
	}
}

int Queue::Deque()
{
	if (IsEmpty())
	{
		cout << "Empty\n";
		return -1;
	}
	else
	{
		mFront++;
		mFront = mFront % mSize;
		return mArr[mFront];
	}
}

int main()
{
	Queue* q = new Queue(20);

	for (int i = 0; i < 19; i++)
	{
		q->Enque(i*i);
	}

	q->Enque(4);
	for (int i = 0; i < 10; i++)
	{
		cout << q->Deque() << endl;
	}

	for (int i = 0; i < 9; i++)
	{
		q->Enque(i * 2);
	}

	cout << "---------------------------------\n";

	for (int i = 0; i < 19; i++)
	{
		cout << q->Deque() << endl;
	}

	delete q;
	return 0;
}
