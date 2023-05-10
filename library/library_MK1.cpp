
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
			cout << "메뉴에 없는 번호 선택. 다시 선택하세요" << endl;
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
			cout << "찾을 항목의 정보를 입력하세요" << endl;
			cout << "검색 : ";
			cin >> selMem;
			cout << "검색 결과" << endl;
			SelectMember(user, selMem);
			break;
		}
		case s_ReArrange:
		{
			int a, b;
			cout << "변경하고싶은 책번호 : ";	cin >> a;	cout << endl;
			cout << "변경하고싶은 위치 : ";		cin >> b;	cout << endl;
			if (b < 1)
			{
				cout << "1 ~ " << user->currentlist << " 중 선택하세요" << endl;
				break;
			}
			if (ChangeList(user, a - 1, b - 1))
				cout << "변경완료" << endl;
			else
				cout << "변경실패" << endl;
			break;
		}
		case s_listresort:
		{
			int seltitle;

			if (user->currentlist == 0)
			{
				cout << "저장된 책이 없습니다" << endl;
				cout << "---------------------------" << endl;
				break;
			}

			cout << "정렬하고싶은 항목선택 " << endl;
			cout << "1. 이름 " << endl;
			cout << "2. 작가 " << endl;
			cout << "3. 총페이지  " << endl;
			cout << "4. 가격 " << endl;
			cin >> seltitle;

			if (seltitle > 4 || seltitle <= 0)
				seltitle = 0;

			if (listresort(user, seltitle))
			{
				cout << "재정렬" << endl;
				cout << "---------------------------" << endl;
			}
			else
			{
				cout << "정렬 실패" << endl;
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
