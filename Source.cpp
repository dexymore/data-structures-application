#include <iostream>
using namespace std;

class stack{
private:
		int max_size;
		int* items;
		int top;
public:
	stack()
	{
		cout << "inter max size";
		cin>> max_size;
		items = new int[max_size];
		top = -1;
	}
	~stack()
	{
		max_size =0;
		top = -1;
		delete(items);
	}
	
	bool is_empty()
	{
		if (top == -1)
		{
			return 1;
		}
		else
			return 0;
	}
	bool is_full()
	{
		if (top == max_size-1)
		{
			return 1;
		}
		else
			return 0;
	}
	void push(int item) {
		if (is_full())
		{
			cout << "stack is full";
			return;
		}
		top++;
		items[top] = item;
	}
	int pop() {
		if (is_empty())
		{
			cout << "stack is empty";
			return -1;
		}
		int data;
		data = items[top];
		top--;
		return data;
	}
	int return_top()
	{
		if (is_empty())
		{
			cout << "stack is empty";
			return -1;
		}
		return items[top];
	
	}
	void print()
	{
		int i = top;
		while (i != -1)
		{
			cout << items[i] << endl;
			i--;
		}
	}
};
int main()
{
	stack a;

	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	cout << a.return_top();
	a.print();








}