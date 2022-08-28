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
		if (rear == -1 || front == -1)
		{
			return 1;
		}
		else return 0;
	}
	bool is_full()
	{
		if ((rear == max_size-1&&front==0)||(front==rear+1))
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
				front=0;
				rear=0;
				items[rear] = item;
				return;
			}
			else
				rear=(rear+1)%max_size;
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
				front = (front + 1) % max_size;
				item = items[front];

			return item;
		}
	}
	void print()
	{
		if (!is_empty())
		{
			if (front <= rear)
			{		for (int i = front; i <= rear; i++)

					cout << items[i] << endl;
			return;
		}
			
			else
				for(int i=front;i<max_size;i++)
					cout << items[i] << endl;
			for (int i = 0; i <=rear; i++)
				cout << items[i] << endl;
		
		}
		else cout << "yuckfo";
	}




};
int main() {
	queue a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.remove();
	a.insert(0);
	a.remove();
	a.remove();
	a.insert(27);
	a.insert(10);
	a.remove();
	a.remove();
	a.insert(7);
	a.insert(2);
	a.print();
}