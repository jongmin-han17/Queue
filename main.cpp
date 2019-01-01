#include <iostream>
using namespace std;

class Queue
{
private:
	int front;
	int rear;
	int size;
	int* arr;
public:
	Queue(int _size) : size(_size), front(0), rear(0)
	{
		arr = new int[size];
	}

	~Queue()
	{
		delete[] arr;
	}

	bool IsEmpty();
	bool IsFull();
	void Enque(int num);
	int Deque();
};

bool Queue::IsEmpty()
{
	return rear == front;
}

bool Queue::IsFull()
{
	return front == (rear + 1) % size;
}

void Queue::Enque(int num)
{
	if (IsFull())
	{
		cout << "Full\n";
	}
	else
	{
		rear++;
		rear = rear % size;
		arr[rear] = num;
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
		front++;
		front = front % size;
		return arr[front];
	}
}

int main()
{
	Queue* q = new Queue(20);

	for (int i=0; i<19; i++)
	{
		q->Enque(i*i);
	}

	for (int i=0; i<10; i++)
	{
		cout << q->Deque() << endl;
	}

	for (int i=0; i<9; i++)
	{
		q->Enque(i*2);
	}

	cout << "---------------------------------\n";

	for (int i=0; i<19; i++)
	{
		cout << q->Deque() << endl;
	}

	delete q;
	return 0;
}