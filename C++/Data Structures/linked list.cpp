#include<bits/stdc++.h>
using namespace std;

struct node{
	ll data;
	node *next;
};

void insert(ll val, node *head)
{
	node *temp = new node();
	temp->data = val;
	temp->next = head;
	head = temp;
}
void remove(ll val, node *head)
{
	if(head->next == NULL)
	{
		cout << "No element in list\n";
		return;
	}
	node *temp = head;
	node *previous = NULL;
	while(temp->data != val || temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	if(temp->next == NULL && temp->data != val)
	{
		cout<<"Value not found!\n";
		return;
	}
	previous->next = temp->next;
	delete(temp);
}
int main()
{
	int choice;
	node *head;
	head->data = 0;
	head->next = NULL;
	while(1)
	{
		cout<<"1) Insert\n 2) Delete\n 3) Search\n 4) Display\n 5) Exit... Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			ll data;
			cin>>data;
			insert(data, head);
			break;

			case 2:
			cin>>data;
			remove(data, head);
			break;

			// case 3:
			// ll data;
			// cin>>data;
			// search(data);
		}
	}
	
	return 0;
}