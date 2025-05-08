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
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

int main(){	
	//save("����.cpp");

	ifstream in{ "����.cpp" };
	if (not in)
		return 2021182009;

	list<STRING> words{ istream_iterator<STRING>{in},{} };

	// [����] ����ڰ� �Է��� �ܾ ����Ʈ�� �ִ� �� �˷�����.
	// �ܾ ������ ���ٶ�� ����ϰ� ������ ����Ʈ�� �� ��° �ܾ����� ����϶�.

	while (true)
	{
		cout << "ã�� �ܾ��? ";
		STRING �ܾ�;
		cin >> �ܾ�;

		auto find_word = find(words.begin(), words.end(), �ܾ�);
		if (find_word == words.end())
		{
			cout << "����" << endl;
		}
		else
		{
			cout << distance(words.begin(), find_word) << endl;
		}
	}

}