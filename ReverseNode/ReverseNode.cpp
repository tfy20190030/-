#include <iostream>

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

Node* ReverseNode(Node* pNode)
{
	Node* next;
	Node* nNext;

	if (NULL == pNode)
		return NULL;

	if (NULL == pNode->next)
		return pNode;

	next = pNode->next;
	pNode->next = NULL;

	while (1)
	{
		nNext = next->next;
		next->next = pNode;
		pNode = next;

		if (NULL == nNext)
			break;

		next = nNext;
	}

	return next;
}

void showData(Node* pNode)
{
	while (pNode)
	{
		std::cout << pNode->data << std::endl;
		pNode = pNode->next;
	}
}
void TraverseNode(Node* pNode)
{
	if (NULL == pNode)
		return;

	if (pNode->next)
	{
		TraverseNode(pNode->next);
	}

	std::cout << pNode->data << std::endl;
}

void test()
{
	Node n1, n2, n3;
	Node* pNode;
	n3.data = 3;
	n3.next = NULL;

	n2.data = 2;
	n2.next = &n3;

	n1.data = 1;
	n1.next = &n2;

	
	

	//pNode = ReverseNode(&n1);
	 TraverseNode(&n1);
	//showData(pNode);

}


int main()
{
	test();
	std::cout << "Hello World!\n";
}