

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
		cout << "BookData 초기화 실패" << endl;
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
		cout << "BookData 초기화 필요" << endl;
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
		cout << "리스트 NULL (removeListElement)" << endl;
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
		cout << "위치 인덱스 오류 (removeListElement)";
		return false;
	}
}



