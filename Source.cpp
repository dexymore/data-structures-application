#include<iostream>
using namespace std;
const int max_size = 5;
class queue {
private:
	int front;
	int rear;
	int items[max_size];
public:
	queue()
	{
		front = -1;
		rear = -1;
	}
	bool is_empty()
	{
		if (rear == -1||front==-1)
		{
			return 1;
		}
		else return 0;
	}
	bool is_full()
	{
		if (rear ==max_size -1)
		{
			return 1;
		}
		else return 0;
	}
	void insert(int item)
	{
		if (is_full())
		{
			cout << "queue is full can't add more items" << endl;
			return;
		}
		else
		{
			if (front == rear && rear == -1)
			{
				front++;
				rear++;
				items[rear] = item;
				return;
			}
			else
				rear++;
			items[rear] = item;
			
		}
	
	}
	int remove()
	{
		int item;
		if (is_empty())
		{
			cout << "queue is empty";
			return-1;
		}
		else
		{
			if (rear == front)
			{
				item = items[rear];
				front = -1;
				rear = -1;
				return item;
			}
			else
				item = items[rear];
				front++;
				return item;
		}
	}
	void print()
	{
		if (!is_empty())
		{
			for (int i = front; i <= rear; i++)
			{
				cout << items[i] << endl;
			}
		}
		else cout << "yuckfo";
	}




};
int main()
{
	queue a;
	a.insert(1);

	a.print();
}