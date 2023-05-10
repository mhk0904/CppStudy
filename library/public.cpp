


#include "header.h"



int Menu(int& val)
{
	cout << "-------------------------------------" << endl;
	cout << "메뉴창" << endl;
	cout << "1. 책 정보 확인" << endl;
	cout << "2. 책 추가" << endl;
	cout << "3. 책 삭제" << endl;
	cout << "4. 저장" << endl;
	cout << "5. 불러오기" << endl;
	cout << "6. 검색" << endl;
	cout << "7. 목록 순서 재배치" << endl;
	cout << "8. 책 정렬" << endl;
	cout << "9. 프로그램 종료" << endl;


	cout << "행동을 선택하세요 : ";
	cin >> val;

	if (cin.fail())
	{
		cerr << "정수형 데이터를 입력하세요" << endl;
		return val = 0;
	}

	cout << endl;
	cout << "-------------------------------------" << endl;
	return val;
}

void ShowArrList(BookData* pbook, int ival)
{
	if (pbook == NULL)
		return;

	cout << "저장된 번호 : " << ival + 1 << endl;
	cout << "책이름 : " << pbook->bookLb[ival].name << endl;
	cout << "작 가 : " << pbook->bookLb[ival].author << endl;
	cout << "총 페이지 : " << pbook->bookLb[ival].page << endl;
	cout << "가격 : " << pbook->bookLb[ival].price << endl;
	cout << "---------------------------" << endl;
}
int SelectBook(BookData* pbook, int chack)
{
	int val = NULL;
	cout << "현재 보관중인 책 : " << pbook->currentlist << endl;
	if (chack == s_AddData)
	{
		cout << "추가할 책 위치 1 ~ " << pbook->currentlist + 1 << "번중 선택: ";
		cin >> val; cout << endl;
	}
	else if (chack == s_DeleteData)
	{
		cout << "삭제할 책 위치 1 ~ " << pbook->currentlist << "번중 선택 : ";
		cin >> val; cout << endl;
	}

	if (val - 1 > pbook->currentlist)
	{
		cout << "선택한 번호는 저장된 책의 수량보다 큽니다." << endl << "다시 선택해주세요";
		return -1;
	}
	else if (val < 0)
	{
		cout << "0보다 작은수는 선택할수 없습니다." << endl << "다시 선택해주세요" << endl;
		return  -1;
	}

	cout << "---------------------------" << endl;
	return val - 1;
}

void InitBookData(BookLib* book)
{
	cout << "-------------------------------------" << endl;
	cout << "책 이름 : ";	cin >> book->name;	cout << endl;
	cout << "작가 : ";		cin >> book->author;	cout << endl;
	cout << "총 페이지 : ";	cin >> book->page;	cout << endl;
	cout << "가격 : ";		cin >> book->price;	cout << endl;
	cout << "-------------------------------------" << endl;

	return;
}


void ShowData(BookData* pbook)
{
	int val;

	if (pbook->currentlist == 0)
	{
		cout << "현재 보관중인 책이없습니다." << endl;
		return;
	}
	cout << "현재 보관중인 책 : " << pbook->currentlist << endl;
	cout << "확인할 책 번호 (0 입력시 모든 책 정보 확인) : ";
	cin >> val; cout << endl;
	if (val > 0)
	{
		ShowArrList(pbook, val - 1);
	}
	else if (val == 0)
	{
		for (int i = 0; i < pbook->currentlist; i++)
		{
			ShowArrList(pbook, i);
		}
	}
	else
		cout << "입력범위 초과" << endl;
	return;
}



void SaveFile(BookData* pbook)
{
	string title;
	if (0 >= pbook->currentlist)
	{
		cout << "저장할 책 정보가 없습니다." << endl;
		cout << "---------------------------" << endl;
		return;
	}

	cout << "저장할 이름을 입력하세요(.txt 작성x) : ";
	cin >> title;

	std::ofstream fout(rootfolder + title + txt);
	if (!fout)
	{
		cout << "저장 실패!!" << endl;
		cout << "---------------------------" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < pbook->currentlist; i++)
		{
			BookLib* savebook = pbook->bookLb;
			fout << savebook[i].name << ",";
			fout << savebook[i].author << ",";
			fout << savebook[i].page << ",";
			fout << savebook[i].price;
			fout << endl;
		}
		cout << "저장 성공" << endl;
		cout << "---------------------------" << endl;
	}
}

void LoadFile(BookData* pbook)
{
	string title;
	cout << "로드할 파일 제목을 입력하세요 : ";
	cin >> title;

	ifstream fin(rootfolder + title + txt);
	string line;
	string token;
	int listnum = 0;

	if (!fin)
	{
		cout << "파일 로드 실패" << endl;
		cout << "---------------------------" << endl;
		return;
	}
	else
	{
		if (pbook == NULL)
			return;
		for (int i = 0; i < pbook->currentlist; i++)
		{
			pbook->bookLb[i].name = "";
			pbook->bookLb[i].author = "";
			pbook->bookLb[i].page = 0;
			pbook->bookLb[i].price = 0;
		}
		pbook->currentlist = 0;

		while (true)
		{
			getline(fin, line);
			stringstream tokenLine(line);
			if (fin.eof())
				break;

			getline(tokenLine, token, ',');
			pbook->bookLb[pbook->currentlist].name = string(token);

			getline(tokenLine, token, ',');
			pbook->bookLb[pbook->currentlist].author = string(token);

			getline(tokenLine, token, ',');
			pbook->bookLb[pbook->currentlist].page = stoi(token);

			getline(tokenLine, token, ',');
			pbook->bookLb[pbook->currentlist].price = stoi(token);

			pbook->currentlist++;
		}
		for (int i = 0; i < pbook->currentlist; i++)
		{
			ShowArrList(pbook, i);
		}
		cout << "로드 성공!!!" << endl;
		cout << "---------------------------" << endl;
	}
}

wstring stows(const string& str) {
	int nLen = MultiByteToWideChar(CP_ACP, 0, &str[0], str.size(), NULL, NULL);
	wstring strUni(nLen, 0);
	MultiByteToWideChar(CP_ACP, 0, &str[0], str.size(), &strUni[0], nLen);
	return strUni;
}

string wstos(const wstring& wstr) {
	int len = WideCharToMultiByte(CP_ACP, 0, &wstr[0], -1, NULL, 0, NULL, NULL);
	string strMulti(len, 0);
	WideCharToMultiByte(CP_ACP, 0, &wstr[0], -1, &strMulti[0], len, NULL, NULL);
	return strMulti;
}
