
#include "header.h"

//BookHeader* createClist(int pos)
//{
//	BookHeader* pbook;
//
//	pbook = new BookHeader;
//
//}


bool LinkCList(BookHeader* pbook, int pos, BookNode pnode)
{
	BookNode* prenode = NULL;
	BookNode* newnode = NULL;
	BookNode* lastnode = NULL;

	if (pos < 0 || pos > pbook->currentlist)
	{
		cout << "Link ���� : position ����" << endl;
		return false;
	}

	newnode = new BookNode;
	*newnode = pnode;
	newnode->link = NULL;
	prenode = pbook->headernode;

	if (pos == 0) 
	{
		if (pbook->currentlist == 0) // ����Ʈ �����϶� �ڽ��� ����
		{
			newnode->link = newnode;
			pbook->headernode = newnode;
		}
		else
		{

			for (int i = 1; i < pbook->currentlist; i++)
				prenode = prenode->link;

			newnode->link = pbook->headernode;
			pbook->headernode = newnode;
			prenode->link = newnode;
	
		}
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			prenode = prenode->link;
		newnode->link = prenode->link;
		prenode->link = newnode;
	}

	pbook->currentlist++;
	return true;
}


bool RemoveCList(BookHeader* pbook, int pos)
{
	BookNode* prenode = NULL,
		* delnode = NULL,
		* lastnode = NULL;

	if (pos < 0 || pos > pbook->currentlist || pbook == NULL)
	{
		cout << "���� ��ġ �ε���" << endl;
		return false;
	}

	if (pos == 0)
	{
		delnode = pbook->headernode;
		if (pbook->currentlist == 1)
		{
			delete delnode;
			pbook->headernode = NULL;
		}
		else
		{
			lastnode = pbook->headernode;
			while (lastnode->link != pbook->headernode)
			{
				lastnode = lastnode->link;
			}
			lastnode->link = delnode->link;
			pbook->headernode = delnode->link;
			delete delnode;
		}
	}
	else
	{
		prenode = pbook->headernode;
		for (int i = 0; i < pos - 1; i++)
			prenode = prenode->link;
		delnode = prenode->link;
		prenode->link = delnode->link;
		delete delnode;
	}
	pbook->currentlist--;
	return true;
}


