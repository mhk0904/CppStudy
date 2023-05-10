


#include "header.h"



int Menu(int& val)
{
	cout << "-------------------------------------" << endl;
	cout << "�޴�â" << endl;
	cout << "1. å ���� Ȯ��" << endl;
	cout << "2. å �߰�" << endl;
	cout << "3. å ����" << endl;
	cout << "4. ����" << endl;
	cout << "5. �ҷ�����" << endl;
	cout << "6. �˻�" << endl;
	cout << "7. ��� ���� ���ġ" << endl;
	cout << "8. å ����" << endl;
	cout << "9. ���α׷� ����" << endl;


	cout << "�ൿ�� �����ϼ��� : ";
	cin >> val;

	if (cin.fail())
	{
		cerr << "������ �����͸� �Է��ϼ���" << endl;
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

	cout << "����� ��ȣ : " << ival + 1 << endl;
	cout << "å�̸� : " << pbook->bookLb[ival].name << endl;
	cout << "�� �� : " << pbook->bookLb[ival].author << endl;
	cout << "�� ������ : " << pbook->bookLb[ival].page << endl;
	cout << "���� : " << pbook->bookLb[ival].price << endl;
	cout << "---------------------------" << endl;
}
int SelectBook(BookData* pbook, int chack)
{
	int val = NULL;
	cout << "���� �������� å : " << pbook->currentlist << endl;
	if (chack == s_AddData)
	{
		cout << "�߰��� å ��ġ 1 ~ " << pbook->currentlist + 1 << "���� ����: ";
		cin >> val; cout << endl;
	}
	else if (chack == s_DeleteData)
	{
		cout << "������ å ��ġ 1 ~ " << pbook->currentlist << "���� ���� : ";
		cin >> val; cout << endl;
	}

	if (val - 1 > pbook->currentlist)
	{
		cout << "������ ��ȣ�� ����� å�� �������� Ů�ϴ�." << endl << "�ٽ� �������ּ���";
		return -1;
	}
	else if (val < 0)
	{
		cout << "0���� �������� �����Ҽ� �����ϴ�." << endl << "�ٽ� �������ּ���" << endl;
		return  -1;
	}

	cout << "---------------------------" << endl;
	return val - 1;
}

void InitBookData(BookLib* book)
{
	cout << "-------------------------------------" << endl;
	cout << "å �̸� : ";	cin >> book->name;	cout << endl;
	cout << "�۰� : ";		cin >> book->author;	cout << endl;
	cout << "�� ������ : ";	cin >> book->page;	cout << endl;
	cout << "���� : ";		cin >> book->price;	cout << endl;
	cout << "-------------------------------------" << endl;

	return;
}


void ShowData(BookData* pbook)
{
	int val;

	if (pbook->currentlist == 0)
	{
		cout << "���� �������� å�̾����ϴ�." << endl;
		return;
	}
	cout << "���� �������� å : " << pbook->currentlist << endl;
	cout << "Ȯ���� å ��ȣ (0 �Է½� ��� å ���� Ȯ��) : ";
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
		cout << "�Է¹��� �ʰ�" << endl;
	return;
}



void SaveFile(BookData* pbook)
{
	string title;
	if (0 >= pbook->currentlist)
	{
		cout << "������ å ������ �����ϴ�." << endl;
		cout << "---------------------------" << endl;
		return;
	}

	cout << "������ �̸��� �Է��ϼ���(.txt �ۼ�x) : ";
	cin >> title;

	std::ofstream fout(rootfolder + title + txt);
	if (!fout)
	{
		cout << "���� ����!!" << endl;
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
		cout << "���� ����" << endl;
		cout << "---------------------------" << endl;
	}
}

void LoadFile(BookData* pbook)
{
	string title;
	cout << "�ε��� ���� ������ �Է��ϼ��� : ";
	cin >> title;

	ifstream fin(rootfolder + title + txt);
	string line;
	string token;
	int listnum = 0;

	if (!fin)
	{
		cout << "���� �ε� ����" << endl;
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
		cout << "�ε� ����!!!" << endl;
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
