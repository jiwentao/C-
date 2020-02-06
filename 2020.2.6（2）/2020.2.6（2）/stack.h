#ifndef _STACK_H_
#define _STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum{Max = 10};
	Item items[Max];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop(Item & item);
};

#endif