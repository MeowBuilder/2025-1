//-----------------------------------------------------------
// 2025.1 �б�		 STL 6�� 2�� ������				(13�� 1��)
// 6/19 ����� 15�� 2�� - �⸻����
//-----------------------------------------------------------
// Associative Container
// - set<key>			: key�� value�� �������� �ʴ´�.
// - Map<key, value>	: <���̵��׷�, ���>
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <array>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

int main(){

	ifstream Alice{ "�̻��� ������ �ٸ���.txt" };
	if (not Alice)
	{
		cout << "������ ����." << endl;
		return 18651126;
	}

	multiset<STRING> s{ istream_iterator<STRING>{Alice},{} };
	cout << "���������ä��Ѥ� �������� :" << s.size() << endl;

	// [����] multiset<STRING> s�� ����� ��� ���ĺ��� ���Ƚ���� ������ ����
	// ���� Ƚ������ ������������ ����϶�
	// �빮�ڴ� �ҹ��ڷ� �ٲ���
	// e - 13618
	// t - 10726
	// ...
	// z - 78

	array<int, 26> a{};

	for (const STRING& word : s)
	{
		for (char ch : word)
		{
			if (isalpha(ch))
			{
				ch = tolower(ch);
				a[ch - 'a']++;
			}
		}
	}


	for (size_t i = 0; i < a.size(); ++i)
	{
		cout << static_cast<char>('a' + i) << " - " << a[i] << endl;
	}

	//save("����.cpp");
}