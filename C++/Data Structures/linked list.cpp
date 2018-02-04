//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


/*-------------------------------------------------------- */

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */

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
		cout<<"No element in list\n";
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
	ll choice;
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