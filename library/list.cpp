

#include "header.h"
//#include "public.cpp"

BookHeader* CreateHaderListNode()
{
	BookHeader* pbook = NULL;

	pbook = new BookHeader;
	if (pbook != NULL) 
	{
		memset(pbook, 0, sizeof(BookHeader));
		pbook->headernode = new BookNode;
		pbook->headernode->link = NULL;
	}
	else
	{
		cout << "BookData �ʱ�ȭ ����" << endl;
		return NULL;
	}
	return pbook;
}
 
bool AddListElement(BookHeader* pbook, int pos, BookNode node)
{
	BookNode* preNode = NULL;
	BookNode* newNode = NULL;

	if (pbook == NULL)
	{
		cout << "BookData �ʱ�ȭ �ʿ�" << endl;
		return false;
	}

	if (pos >= 0 && pos <= pbook->currentlist)
	{
		newNode = new BookNode;

		if (newNode == NULL)
		{
			cout << "node == NULL" << endl;
			return false;
		}

		*newNode = node;
		newNode->link = NULL;

		preNode = pbook->headernode;
		for (int i = 0; i < pos; i++)
			preNode = preNode->link;

		newNode->link = preNode->link;	// nullptr?
		preNode->link = newNode;

		pbook->currentlist++;
	}
	return true;
}

bool RemoveListElement(BookHeader* pbook, int pos)
{
	BookNode* pNode = NULL;
	BookNode* delNode = NULL;

	if (pbook == NULL)
	{
		cout << "����Ʈ NULL (removeListElement)" << endl;
		return false;
	}
	
	if (pos >= 0 && pos < pbook->currentlist)
	{
		pNode = pbook->headernode;
		for (int i = 0; i < pos; i++)
		{
			pNode = pNode->link;
		}
		delNode = pNode->link;
		pNode->link = delNode->link;
		delete delNode;

		pbook->currentlist--;
		return true;
	}
	else
	{
		cout << "��ġ �ε��� ���� (removeListElement)";
		return false;
	}
}



