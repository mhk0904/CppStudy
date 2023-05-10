
#include "header.h"
//#include "public.cpp"

int main()
{
	int stat = 0;
	int selectBookNum = -1;
	BookData* user = NULL;
	BookLib book;

	user = CreateLibrary(100);


	while (true)
	{
		Menu(stat);
		if (stat <= s_None || stat > s_End)
		{
			cout << "�޴��� ���� ��ȣ ����. �ٽ� �����ϼ���" << endl;
		}
		switch (stat)
		{
		case s_ShowData:
		{
			ShowData(user);

			break;
		}
		case s_AddData:
		{
			selectBookNum = SelectBook(user, s_AddData);
			if (selectBookNum == -1)
				break;
			AddBookData(user, selectBookNum);
			break;

		}
		case s_DeleteData:
		{
			selectBookNum = SelectBook(user, s_DeleteData);
			if (selectBookNum == -1)
				break;
			removeBookData(user, selectBookNum);
			break;
		}
		case s_Save:
		{
			SaveFile(user);
			break;
		}
		case s_Load:
		{
			LoadFile(user);
			break;
		}
		case s_Selectbook:
		{
			string selMem;
			cout << "ã�� �׸��� ������ �Է��ϼ���" << endl;
			cout << "�˻� : ";
			cin >> selMem;
			cout << "�˻� ���" << endl;
			SelectMember(user, selMem);
			break;
		}
		case s_ReArrange:
		{
			int a, b;
			cout << "�����ϰ���� å��ȣ : ";	cin >> a;	cout << endl;
			cout << "�����ϰ���� ��ġ : ";		cin >> b;	cout << endl;
			if (b < 1)
			{
				cout << "1 ~ " << user->currentlist << " �� �����ϼ���" << endl;
				break;
			}
			if (ChangeList(user, a - 1, b - 1))
				cout << "����Ϸ�" << endl;
			else
				cout << "�������" << endl;
			break;
		}
		case s_listresort:
		{
			int seltitle;

			if (user->currentlist == 0)
			{
				cout << "����� å�� �����ϴ�" << endl;
				cout << "---------------------------" << endl;
				break;
			}

			cout << "�����ϰ���� �׸��� " << endl;
			cout << "1. �̸� " << endl;
			cout << "2. �۰� " << endl;
			cout << "3. ��������  " << endl;
			cout << "4. ���� " << endl;
			cin >> seltitle;

			if (seltitle > 4 || seltitle <= 0)
				seltitle = 0;

			if (listresort(user, seltitle))
			{
				cout << "������" << endl;
				cout << "---------------------------" << endl;
			}
			else
			{
				cout << "���� ����" << endl;
				cout << "---------------------------" << endl;
			}
			break;
		}
		case s_End:
		{
			if (user != NULL) {
				if (user->bookLb != NULL) {
					delete[] user->bookLb;
					delete(user);
				}
			}
			return 0;
			break;
		}
		}
	}
}
