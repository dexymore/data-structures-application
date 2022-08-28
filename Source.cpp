#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int value)
	{
		data = value;
		next = NULL;
	}
////////////////////////////////////////
};
class linked_list {
private:
	node *list;
public:
	linked_list()
	{
		list = NULL;
	}
	void add_first(int item)
	{
		node* ptr = new node(item);
		if (list == NULL)
		{
			list = ptr;
			return;
		}
		else
		ptr->next = list;
			list = ptr;
	
	}
	void add_last(int item){
		node* ptr = new node(item);
		node* q = list;
		
		if (list == NULL)
		{
			list = ptr;
		}
		else

			while (q->next != NULL)
				q = q->next;
		q->next = ptr;
	}
	void add_after(int item,int pos)
	{	
		node* q = list;
		int i=0;
		while (q != NULL &&  i<pos)
		{
			q = q->next;
			i++;
		}
		if (q == NULL || i != pos)
		{

			cout << "can't add to the following postion";
			return ;
		}
		node* ptr = new node(item);
		ptr->next = q->next;
		q->next = ptr;
	}
	int remove_first()
	{
	if(list==NULL)
	{
		cout << "linked list is empty";
		return -1;
	}
	else {
		int item;
		item = list->data;
		if (list->next == NULL)
		{
			delete(list);
			list = NULL;
	
		}
		else {
			node* ptr = list;
			list = list->next;
			delete (ptr);
		
		}
		return item;

	}
	}
	int remove_last()
	{
		if (list == NULL)
		{
			cout << "list is empty";
			return -1;
		}
		else
		{
			int item;
			if (list->next == NULL)
			{
				item = list->data;
				delete(list);
				list = NULL;
				return item;
			}
			else {
				node* ptr=list;
				while (ptr->next->next != NULL)
					ptr=ptr->next;
				item = ptr->next->data;
				delete (ptr->next);
				ptr ->next = NULL;
				return item;
			}
	

		
		}
	
	
	}
	int search(int item)
	{
		node* ptr = list;
		int pos = 0;
		while (ptr != NULL && ptr->data != item)
		{
			ptr = ptr->next;
			pos++;
		}
		if (ptr == NULL)
		{
			return -1;
	
		}
		return pos;
	}
	void remove_item(int item)
	{
		
		if (list == NULL)
		{
			cout << "list is empty";
			return;
		}
		else if (list->data== item)		
		{
			remove_first();
			return;
		}
		node* ptr = list;
		while (ptr->next != NULL && ptr->next->data != item)
			ptr = ptr->next;
		if (ptr->next == NULL)
		{
			cout << "yaraab";
			return;
		}
		node* q = ptr->next;
		ptr->next = q->next;
		delete (q);
	}
	void display()
	{
		if (list == NULL)
			cout << "list is empty";
		else
		{
			node* ptr = list;
			while (ptr != NULL)
			{
				cout << ptr->data<<" ";
				ptr = ptr->next;
			}
			cout << endl;
		}
	}
};
int main()
{
	linked_list ahmed;
	ahmed.add_first(3);
	ahmed.add_first(2);
	ahmed.add_first(1);
	ahmed.add_last(6);
	ahmed.add_after(5, 1);
	ahmed.remove_item(5);

	
	ahmed.display();
}