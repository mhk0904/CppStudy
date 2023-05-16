
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <Windows.h>

using namespace std;

static string rootfolder = "data\\";
static string txt = ".txt";

enum status {
	s_None,
	s_ShowData,
	s_AddData,
	s_DeleteData,
	s_Save,
	s_Load,
	s_Selectbook,
	s_ReArrange,
	s_listresort,
	s_End,
};



typedef struct Book {
	string	name,
		author ;
	int		page	,
			price	;
}BookLib;


typedef struct BookArr {
	int maxlist		,
		currentlist ;
	BookLib* bookLb;
}BookData;

/////////////////////////////////////////


typedef struct Booklink {
	string	name	,
			author	;
	int		page	,
			price	;
	Booklink* link;
}BookNode;

typedef struct BookHD {
	int maxlist		,
		currentlist ;
	BookNode* headernode;
} BookHeader;


//template <typename T>
//void ShowData(T* pbook);


//( public )
int Menu(int& val);
int SelectBook(BookData* pbook, int chack);
void InitBookData(BookLib* book);
void SaveFile(BookData* pbook);
void LoadFile(BookData* pbook);
string wstos(const wstring& wstr);
wstring stows(const string& str);			// string to wstring
void ShowArrList(BookData* pbook, int i);
void ShowData(BookData* pbook);


//( arrange )
BookData* CreateLibrary(int max);
void AddBookData(BookData* pData, int pos);
bool FullListChack(BookData* pData, int icur);
void removeBookData(BookData* book, int pos);
bool SelectMember(BookData* pbook, string selMem);
bool ChangeList(BookData* pbook, int val_1, int val_2);
bool listresort(BookData* pbook, int ival);



//( list )
BookHeader* CreateHaderListNode();
bool AddListElement(BookHeader* pbook, int pos, BookNode node);
bool RemoveListElement(BookHeader* pbook, int pos);

