#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */
struct node
{
	int currentValue;
	node *leftPtr;
	node *rightPtr;		
	node()
	{
		currentValue = 0;
		leftPtr = NULL;
		rightPtr = NULL;
	}
};
class binarySearchTree{
	node *root;	
public:
	void insertNode(int valueOfNode, node *root)
	{
		if(root == NULL)
		{
			root->currentValue = valueOfNode;
			root->leftPtr = NULL;
			root->rightPtr = NULL;
		}
		else
		{
			if(root->currentValue > valueOfNode)
			{
				insertNode(valueOfNode, root->leftPtr);
			}
			else
			{
				insertNode(valueOfNode, root->rightPtr);
			}
		}
	}
};
int main()
{
	fastread;
	
	return 0;
}
