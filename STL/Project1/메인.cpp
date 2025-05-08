//-----------------------------------------------------------
// 2025.1 �б�		 STL 5�� 08�� �����				(9�� 2��)
// 6/19 ����� 15�� 2�� - �⸻����
// 5/12 ������ - ������ǰ �߰���ǥ������ �Ѵ�.
//-----------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array<T,N> - �����ϰ� ũ�Ⱑ ����
// vector<T> - random access�� ����(== [] ������ ����), O(1)(����ð�) access, O(1) push_back()
// deque<T> - random access, []������, O(1) access, O(1) push_front(), push_back()
// list<T> - O(1) insert, delete, �ڷᱸ���� Ȱ���� �����Լ� ����(remove, sort, splice)
// STL�� �˰��� 1.����X 2.����O 3.����
//-----------------------------------------------------------

#include <iostream>
#include <vector>
#include <deque>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

class Test
{
	char x[1'000'000];
};

int main(){	
	{
		vector<Test> vec;
		while (true) {
			try
			{
				vec.emplace_back();
			}
			catch (const std::exception& e)
			{
				cout << e.what() << endl;
				cout << "�ִ� ���� - " << vec.size() << endl;
				break;
			}
		}
	}

	//save("����.cpp");
}