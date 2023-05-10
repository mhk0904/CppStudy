

#include "header.h"
//#include "public.cpp"


BookData* CreateLibrary(int max)
{
	BookData *pData = NULL;
	pData = new BookData;

	if (max > 0)
	{
		pData->maxlist = max;
		pData->currentlist = 0;
		pData->bookLb = NULL;
	}
	else
	{
		cout << "error CrateLibrary : BookData != NULL" << endl;
		return NULL;
	}

	pData->bookLb = new BookLib[max];

	if (pData->bookLb == NULL) 
	{
		cout << "error CrateLibrary : BookLb != NULL" << endl;
		return NULL;
	}
		
	memset(pData->bookLb, 0, sizeof(BookLib) * max);
	
	return pData;
}

bool FullListChack(BookData* pData ,int icur)
{
	if (pData != NULL)
		if (pData->maxlist == icur)
			return true;

	return false;
}

void AddBookData(BookData* pData, int pos)
{
	BookLib pElm;
	InitBookData(&pElm);
	if (pData == NULL) 
	{
		cout << "배열 생성 오류 AddBookData  error" << endl;
		return;
	}
	
	if (FullListChack(pData, pos))
	{
		cout << "최대 배열 초과 AddBookData  error " << endl;
		return;
	}

	if (pos >= 0 && pos <= pData->currentlist)
	{
		for (int i = pData->currentlist - 1; i >= pos; i--)
		{
			pData->bookLb[i + 1] = pData->bookLb[i];
		}
		pData->bookLb[pos] = pElm;
		pData->bookLb[pos].name = pElm.name;
		pData->bookLb[pos].author = pElm.author;
		pData->currentlist++;
	}
	else
	{
		cout << "배열 위치 초과  AddBookData  error" << endl;
		return;
	}

	cout << "책 정보가 추가 되었습니다." << endl;
	cout << "---------------------------" << endl;
	return;
}


void removeBookData(BookData *book,int pos)
{
	if (book == NULL)
		return;

	if (pos >= 0 && pos <= book->currentlist)
	{
		for (int i = pos; i <= book->currentlist - 1; i++)
			book->bookLb[i] = book->bookLb[i + 1];
		book->currentlist--;
		cout << "보관중인 책 " << pos +1<< "번 삭제" << endl;
	}
	else
	{
		cout << "삭제할 책번호 오류 removeBookData error" << endl;
	}
	cout << "---------------------------" << endl;
	return;
}


bool StrToInt(string sval)	//47~57
{
	for (unsigned int i = 0; i < sval.length(); i++)
	{
		if (!(sval[i] >= '0' && sval[i] <= '9'))
			return false;
	}
	return true;
}

bool SelectMember(BookData* pbook, string selMem)
{
	bool chack = false;

	int selint=0;
	if (StrToInt(selMem)) 
	{
		selint = stoi(selMem);
	}
	
	for (int i = 0; i < pbook->currentlist; i++)
	{
		if (pbook->bookLb[i].name == selMem)
		{
			ShowArrList(pbook, i);
			chack = true;
		}
		else if (pbook->bookLb[i].author == selMem)
		{
			ShowArrList(pbook, i);
			chack = true;
		}
		if (StrToInt(selMem))
		{
			if (pbook->bookLb[i].page == selint)
			{
				ShowArrList(pbook, i);
				chack = true;
			}
			else if (pbook->bookLb[i].price == selint)
			{
				ShowArrList(pbook, i);
				chack = true;
			}
		}
	}
	if (!chack)
	{
		cout << "검색결과없음" << endl;
		return false;
	}
	else
		return true;
}


bool ChangeList(BookData* pbook, int val_1, int val_2)
{
	if (val_1 > pbook->currentlist || val_2 > pbook->currentlist)
	{
		cout << "현재저장된수보다 입력값이큽니다." << endl;
		return false;
	}
	BookLib tempbook = pbook->bookLb[val_1];
	pbook->bookLb[val_1] = pbook->bookLb[val_2];
	pbook->bookLb[val_2] = tempbook;
	tempbook = pbook->bookLb[val_1];
	return true;
}


bool listresort(BookData* pbook, int ival)
{
	wstring val1, val2;

	if (ival == 1|| ival == 2)
	{
		for (int i = 0; i < pbook->currentlist; i++)
		{
			for (int j = i + 1; j < pbook->currentlist; j++)
			{
				if (ival == 1)
				{
					val1 = stows(pbook->bookLb[i].name);
					val2 = stows(pbook->bookLb[j].name);
				}
				else
				{
					val1 = stows(pbook->bookLb[i].name);
					val2 = stows(pbook->bookLb[j].name);
				}
				if (val1 > val2)
				{
					ChangeList(pbook, j, i);
					if (i > 0)
					{
						i--;
					}
					j = i + 1;
				}
			}
		}
	}
	else if(ival == 3 || ival == 4)
	{
		for (int i = 0; i < pbook->currentlist; i++)
		{
			for (int j = i + 1; j < pbook->currentlist; j++)
			{
				if (ival == 3) 
				{
					if (pbook->bookLb[i].page > pbook->bookLb[j].page)
					{
						ChangeList(pbook, j, i);
						if (i > 0)
						{
							i--;
						}
						j = i + 1;
					}
				}
				else
				{
					if (pbook->bookLb[i].price > pbook->bookLb[j].price)
					{
						ChangeList(pbook, j, i);
						if (i > 0)
						{
							i--;
						}
						j = i + 1;
					}
				}
			}
		}
	}
	return true;
}
