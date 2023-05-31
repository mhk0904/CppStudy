
#include "header.h"

DoubleList* CreateDoubleList()
{
	DoubleList* preturn = NULL;
	preturn = new DoubleList;

	if (preturn != NULL)
	{
		memset(preturn, 0, sizeof(DoubleList));
		preturn->headerNode->NextLink = new DoubleListNode;
		preturn->headerNode->preLink = new DoubleListNode;

	}
	else
	{
		cout << "메모리할당오류" << endl;
		return NULL;
	}
	return preturn;
}


bool add_DL_Element(DoubleList* plist, int pos, DoubleListNode element)
{
	DoubleListNode* prenode = NULL, * newnode = NULL;

	if (plist == NULL || pos < 0 || pos > plist->currentelement)
	{
		cout << "인덱스 오류" << endl;
		return false;
	}

	*newnode = element;
	newnode->NextLink = NULL;
	newnode->preLink = NULL;

	prenode = plist->headerNode;
	for (int i = 0; i < pos; i++)
	{
		prenode = prenode->NextLink;
	}

	newnode->preLink = prenode;
	newnode->NextLink = prenode->NextLink;
	prenode->NextLink = newnode;
	newnode->NextLink->preLink = newnode;

	plist->currentelement++;

	return true;
}

bool Remove_DL_Element(DoubleList* plist, int pos)
{
	DoubleListNode* prenode = NULL, * delnode = NULL;

	if (pos < 0 || pos > plist->currentelement)
	{
		cout << "인덱스 오류" << endl;
		return false;
	}

	prenode = plist->headerNode;
	for (int i = 0; i < pos; i++)
		prenode = prenode->NextLink;
	delnode = prenode->NextLink;

	prenode->NextLink = delnode->NextLink;
	delnode->NextLink->preLink = prenode;
	delete delnode;

	plist->currentelement--;
	return true;
}

