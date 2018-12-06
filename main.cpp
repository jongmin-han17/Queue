//Queue in C++
//Written by Jongmin Han
//jongmin.han17@gmail.com
#include <iostream>
using namespace std;

class Queue //This is circular queue.
{
private:
    int front;
    int rear;
    int size;
	int * arr;
public:
	Queue(int _size)
	{
		size = _size;
		arr = new int[_size];
		front = 0;
		rear = 0;
	}

	~Queue()
	{
		delete []arr;
	}

	bool isEmpty();
	bool isFull();
	void enque(int num);
	int deque();
};

bool Queue::isEmpty()
{
	return front == rear ? true : false;
}

bool Queue::isFull()
{
	return front == (rear+1) % size ? true : false;
}

void Queue::enque(int num)
{
	if (isFull())
		cout << "Full\n";
	else
	{
	    rear++;
		rear = rear % size;
		arr[rear] = num;
	}
}

int Queue::deque()
{
	if (isEmpty())
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
	Queue * q = new Queue(20);

	for (int i=0; i<19; i++)
		q->enque(i*i);

	for (int i=0; i<10; i++)
		cout << q->deque() << endl;

    for (int i=0; i<9; i++)
        q->enque(i*2);

    cout << "-------------------------\n";
    for (int i=0; i<19; i++)
		cout << q->deque() << endl;

	delete q;
	return 0;
}
