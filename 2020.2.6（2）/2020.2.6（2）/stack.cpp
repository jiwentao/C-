#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"

Stack::Stack()
{
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == Max;
}

bool Stack::push(const Item & item)
{
	if(top < Max)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item & item)
{
	if(top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}