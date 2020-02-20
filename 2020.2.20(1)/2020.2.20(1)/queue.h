#ifndef _QUEUE_H_
#define _QUEUE_H_

template<typename Item>
class Queue
{
private:
	enum {Q_SIZE = 10};
	class Node
	{
	public:
		Item item;
		Node * next;
		Node(const Item & i) : item(i),next(0) {}
	};
	Node * front;
	Node * rear;
	int items;
	const int qsize;
	Queue(const Queue & q) : qsize(0) {}
	Queue & operator=(const Queue & q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const { return items == 0; }
	bool isfull() const { return items == qsize; }
	int queuecount() const { return items; }
	bool enqueue(const Item & item);
	bool dequeue(Item & item);
};
template<typename Item>
Queue<Item>::Queue(int qs) : qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

template<typename Item>
Queue<Item>::~Queue()
{
	Node * temp;
	while(front != 0)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename Item>
bool Queue<Item>::enqueue(const Item & item)
{
	if(isfull())
		return false;
	Node * add = new Node(item);
	items++;
	if(front == 0)
		front = add;
	else
	    rear->next = add;
	rear = add;
	return true;
}

template<typename Item>
bool Queue<Item>::dequeue(Item & item)
{
	if(isempty())
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if(items == 0)
		rear = 0;
	return true;
}
#endif