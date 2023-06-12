#include "stack.h"

int main()
{
	stack* pstack = NULL;
	stacknode* pnode = NULL;


	pstack = creatarraystack(6);
	if (pstack != NULL)
	{
		stacknode node2 = { 'B' };
		stacknode node1 = { 'A' };
		stacknode node3 = { 'C' };
		stacknode node4 = { 'D' };

		pushas(pstack, node1);
		showarraydata(pstack);
		pushas(pstack, node2);
		showarraydata(pstack);
		pushas(pstack, node3);
		showarraydata(pstack);
		pushas(pstack, node4);
		
		showarraydata(pstack);

		pnode = popas(pstack);
		if (pnode != NULL)
		{
			cout << "pop값" << pnode->data << endl;
			delete pnode;
		}
		showarraydata(pstack);

		pnode = popas(pstack);
		if (pnode != NULL)
		{
			cout << "pop값" << pnode->data << endl;
			delete pnode;
		}
		showarraydata(pstack);

		pnode = popas(pstack);
		if (pnode != NULL)
		{
			cout << "pop값" << pnode->data << endl;
			delete pnode;
		}
		showarraydata(pstack);

		pnode = peekas(pstack);
		if (pnode != NULL)
			cout << "peek값" << pnode->data << endl;

		showarraydata(pstack);
		for (int i = 6 - 1; i >= 0; i--)
		{
			cout << i << " " << pstack->element[i].data << endl;
		}
	}

	return 0;
}



stack* creatarraystack(int size)
{
	stack* preturn = NULL;

	preturn = new stack;
	if (size <= 0)
		return NULL;

	if (preturn != NULL)
	{
		memset(preturn, 0, sizeof(stack));
		preturn->maxelementcount = size;
	}
	else
		return NULL;

	preturn->element = new stacknode;

	if (preturn->element != NULL)
	{
		memset(preturn->element, 0, sizeof(stacknode) * size);
	}
	else
		return NULL;

	return preturn;
}

bool pushas(stack* pstack, stacknode element)
{
	if (!arraystackfull(pstack))
		return false;

	pstack->element[pstack->currentelementcount] = element;
	pstack->currentelementcount++;
	
	return true;
}

stacknode* popas(stack* pstack)
{
	stacknode* preturn = NULL;
	if (!arraystackfull(pstack))
		return preturn;

	preturn = new (stacknode);
	*preturn = pstack->element[pstack->currentelementcount - 1];
	pstack->currentelementcount--;
	return preturn;
}

stacknode* peekas(stack* pstack)
{
	stacknode* preturn = NULL;
	if (!arraystackfull(pstack))
		return preturn;
	preturn = &(pstack->element[pstack->currentelementcount - 1]);
	return preturn;
}


bool arraystackfull(stack* pstack)
{
	if (pstack->currentelementcount == pstack->maxelementcount)
		return false;
	else
		return true;
}

void showarraydata(stack* pstack)
{
	if (pstack == NULL)
		return;

	int size =pstack->maxelementcount;
	int top = pstack->currentelementcount;

	cout << "크기 " << pstack->maxelementcount << "개수 " << pstack->currentelementcount << endl;

	for (int i = size - 1; i >= top; i--)
	{
		cout << i << " 공백" << endl;
	}

	for (int i = top - 1; i >= 0; i--)
	{
		cout << i << " " << pstack->element[i].data << endl;
	}
}